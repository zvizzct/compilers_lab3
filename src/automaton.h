#include "initGrammar.h"
#include "stack.h"
#include "processInput.h"

/**
 * @brief Write the reduce action and the updated stack content in the output file
 * @param output_file Output file where the information will be written
 * @param production Production rule used for reducing
 * @param new_state New state of the stack after reducing
 * @param stack Pointer to the stack being used
 */
void printReduce(FILE *output_file, production_rule production, int new_state, Stack *stack)
{
    fprintf(output_file, "REDUCE: %s->%s", production.lhs, production.rhs);
    for (int i = 0; i < 12 - strlen(production.rhs); i++)
    {
        if (i == 6 - strlen(production.rhs))
            fprintf(output_file, "|");
        fprintf(output_file, " ");
    }
    if (new_state < 10)
        fprintf(output_file, "%d      ", new_state);
    else
        fprintf(output_file, "%d     ", new_state);
    printStack(*stack, output_file);
}

/**
 * @brief Reduce the stack according to the production rule
 * @param production Production rule used for reducing
 * @param stack Pointer to the stack being used
 * @param goto_table GOTO table for the automaton being used
 * @param output_file Output file where the information will be written
 */
void reduce(production_rule production, Stack *stack, int **goto_table, FILE *output_file)
{
    StackElement popped;
    for (int i = 0; i < production.rhs_len; i++)
    {
        popped = pop(stack);
    }
    int new_current_state = peek(stack).state;
    int new_state = goto_table[new_current_state][production.lhs_index];
    StackElement *new_element = createStackElement(production.lhs, new_state);
    push(stack, new_element);
    printReduce(output_file, production, new_state, stack);
}

/**
 * @brief Write the shift action and the updated stack content in the output file
 * @param output_file Output file where the information will be written
 * @param stack Pointer to the stack being used
 * @param next_state Next state of the stack after shifting
 */
void printShift(FILE *output_file, Stack *stack, int next_state)
{
    if (next_state < 10)
        fprintf(output_file, "   SHIFT         |      %d      ", next_state);
    else
        fprintf(output_file, "   SHIFT         |      %d     ", next_state);
    printStack(*stack, output_file);
}
/**

 * @brief Shift the stack according to the token
 * @param stack Pointer to the stack being used
 * @param token_lexeme Lexeme of the token being shifted
 * @param next_state Next state of the stack after shifting
 * @param output_file Output file where the information will be written
 */
void shift(Stack *stack, char token_lexeme[], int next_state, FILE *output_file)
{
    StackElement *new_element = createStackElement(token_lexeme, next_state);
    push(stack, new_element);
    printShift(output_file, stack, next_state);
}

/**
 * @brief Write the current state and current input token in the output file
 * @param output_file Output file where the information will be written
 * @param current_state Current state of the stack
 * @param token_lexeme Lexeme of the token being processed
 */
void printStateInput(FILE *output_file, int current_state, char token_lexeme[])
{
    if (current_state < 10)
        fprintf(output_file, "      %d         |        %s        |    ", current_state, token_lexeme);
    else
        fprintf(output_file, "      %d        |        %s        |    ", current_state, token_lexeme);
}

/**
 * @brief Runs the automaton for the given input tokens and writes the actions taken to the output file
 * @param productions Array of production rules for the grammar
 * @param action_table Table of actions for the LR parser
 * @param goto_table Table of gotos for the LR parser
 * @param tokens Array of tokens representing the input to be parsed
 * @param num_tokens Number of tokens in the input
 * @param output_file Output file where the actions taken will be written
 */
void runAutomaton(production_rule *productions, Action **action_table, int **goto_table, Token tokens[], int num_tokens, FILE *output_file)
{
    // Initialize stack
    Stack *stack = createStack();

    fprintf(output_file, "Current state   |  Current input  |      Action         |  New state  |         Stack\n");
    int current_state;
    int i = 0;
    while (i < num_tokens)
    {
        current_state = peek(stack).state;
        printStateInput(output_file, current_state, tokens[i].lexeme);
        Action current_action = action_table[current_state][tokens[i].index];
        if (current_action.type == REDUCE)
        {
            reduce(productions[current_action.state_or_production], stack, goto_table, output_file);
        }
        else if (current_action.type == SHIFT)
        {
            shift(stack, tokens[i].lexeme, current_action.state_or_production, output_file);
            i++;
        }
        else if (current_action.type == ACCEPT)
        {
            printf("Input accepted, the sequence of tokens is correct\n");
            fprintf(output_file, "   ACCEPT        |             |");
            break;
        }
        else
        {
            printf("Input rejected, the sequence of tokens is not correct\n");
            fprintf(output_file, "   ERROR         |             |");
            break;
            ;
        }
    }
}