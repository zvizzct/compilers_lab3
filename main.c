/*
 * @file main.c
 * @brief Main file for the preprocessor app that calls the other functions to process the file
 * content and save it to a new file.
 */

#include <stdio.h>
#include <stdlib.h>
#include "src/stack.h"
#include "utilsAction.h"
#include "action_table.h"
#include "goto_table.h"

int main(int argc, char const *argv[])
{
    // Initialize grammar
    production_rule productions[7] = initProductions();

    // Initialize stack
    stack stack;
    stack_entry initial_element = {-1, 0};
    stack.entries[0] = initial_element;

    // Initialize tables
    init_action_table();
    init_goto_table();

    // Get tokens 
    int tokens[] = {LEFT_PARENTHESIS, NUM, PLUS};
    int num_token = 3;
    int current_state;

    int i = 0;
    while (tokens[i] != NULL) {
        current_state = getTopStack(stack).state;
        Action current_action = action_table[current_state][tokens[i]];
        if (current_action.type == REDUCE){
            reduce(productions[current_action.state_or_production], stack);
        }
        else if (current_action.type == SHIFT) {
            shift(stack, tokens[i], current_action.state_or_production);
            i++;
        }
        else if (current_action.type == ACCEPT) {
            printf("DFA is done\n");
        }
        else {
            printf("Error\n");
        }
    }
    return 0;
}
