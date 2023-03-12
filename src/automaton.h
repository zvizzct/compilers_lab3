#include "initGrammar.h"
#include "stack.h"
#include "processInput.h"

/**
 * Write the reduce action and the updated stack content in the outputfile
*/
void printReduce(FILE* output_file, production_rule production, int new_state, Stack *stack) {
    fprintf(output_file, "REDUCE: %s->%s", production.lhs, production.rhs);
    for (int i = 0; i < 12-strlen(production.rhs); i++)
    {
        fprintf(output_file, " ");
    }
    if (new_state < 10) fprintf(output_file, "%d           ", new_state);
    else fprintf(output_file, "%d          ", new_state);
    printStack(*stack, output_file);
}

void reduce(production_rule production, Stack *stack, int** goto_table, FILE *output_file)
{
    StackElement popped;
    for (int i = 0; i < production.rhs_len; i++)
    {
        popped = pop(stack);
    }
    int new_current_state = peek(stack).state;
    int new_state = goto_table[new_current_state][production.lhs_index];
    StackElement* new_element = createStackElement(production.lhs, new_state);
    push(stack, new_element);
    printReduce(output_file, production, new_state, stack);
}

/**
 * Write the shift action and the updated stack content in the outputfile
*/
void printShift(FILE* output_file, Stack *stack, int next_state) {
    if (next_state < 10) fprintf(output_file, "   SHIFT               %d           ", next_state);
    else fprintf(output_file, "   SHIFT               %d          ", next_state);
    printStack(*stack, output_file);
}

void shift(Stack *stack, char token_lexeme[], int next_state, FILE *output_file)
{
    StackElement *new_element = createStackElement(token_lexeme, next_state);
    push(stack, new_element);
    printShift(output_file, stack, next_state);
}

void printStateInput(FILE* output_file, int current_state, char token_lexeme[] ) {
    if (current_state < 10) fprintf(output_file, "      %d                  %s           ", current_state, token_lexeme);
    else fprintf(output_file, "      %d                 %s           ", current_state, token_lexeme);
}

void runAutomaton(production_rule* productions, Action** action_table, int** goto_table, Token tokens[], int num_tokens, FILE *output_file) {
    // Initialize stack
    Stack *stack = createStack();

    fprintf(output_file, "Current state      Current input       Action           New state                Stack\n");
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
            printf("Input accepted\n");
            fprintf(output_file, "   ACCEPT");
            break;
        }
        else
        {
            printf("Input rejected\n");
            fprintf(output_file, "   ERROR");
            break;;
        }
    }
}