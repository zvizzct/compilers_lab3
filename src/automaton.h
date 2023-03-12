#include "initGrammar.h"
#include "stack.h"
#include "processInput.h"

void reduce(production_rule production, Stack *stack, int** goto_table, FILE *output_file)
{
    StackElement popped;
    for (int i = 0; i < production.rhs_len; i++)
    {
        popped = pop(stack);
    }
    int new_current_state = peek(stack).state;
    int new_state = goto_table[new_current_state][production.lhs];
    fprintf(output_file, "REDUCE   new state : %d", new_state);
    StackElement new_element = {production.lhs, new_state};
    push(stack, new_element);
}

void shift(Stack *stack, int token, int next_state, FILE *output_file)
{
    fprintf(output_file, "SHIFT   next state : %d", next_state);
    StackElement new_element = {token, next_state};
    push(stack, new_element);
}

void runAutomaton(production_rule* productions, Action** action_table, int** goto_table, Token tokens[], int num_tokens, FILE *output_file) {
    // Initialize stack
    Stack stack;
    StackElement initial_element = {1, 0};
    init(&stack);
    push(&stack, initial_element);
    
    int current_state;
    int i = 0;
    while (i < num_tokens)
    {
        current_state = peek(&stack).state;
        fprintf(output_file, "current state : %d   ", current_state);
        Action current_action = action_table[current_state][tokens[i].index];
        if (current_action.type == REDUCE)
        {
            reduce(productions[current_action.state_or_production], &stack, goto_table, output_file);
            // print in the output file
        }
        else if (current_action.type == SHIFT)
        {
            shift(&stack, tokens[i].index, current_action.state_or_production, output_file);
            i++;
            // print in the output file
        }
        else if (current_action.type == ACCEPT)
        {
            printf("Input accepted\n");
            fprintf(output_file, "ACCEPT");
            break;
        }
        else
        {
            printf("Input rejected\n");
            fprintf(output_file, "ERROR");
            break;;
        }
        fprintf(output_file, "\n");
    }
}