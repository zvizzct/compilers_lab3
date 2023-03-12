#include "actionTable.h"
#include <stdlib.h>

Action** create_action_table(int num_state, int num_symbol)
{
    // Allocate the memory for the action table
    Action** action_table = malloc(num_state * sizeof(Action*));
    for (int i = 0; i < num_state; i++) {
        action_table[i] = malloc(num_symbol * sizeof(Action));
    }

    // initialize the action table
    for (int i = 0; i < num_state; i++)
    {
        for (int j = 0; j < num_symbol; j++)
        {
            action_table[i][j].type = ERROR;
            action_table[i][j].state_or_production = -1;
        }
    }
    return action_table;
}
void set_shift_action(Action** action_table, int state, int symbol, int next_state)
{
    action_table[state][symbol].type = SHIFT;
    action_table[state][symbol].state_or_production = next_state;
}

void set_reduce_action(Action** action_table, int state, int symbol, int production)
{
    action_table[state][symbol].type = REDUCE;
    action_table[state][symbol].state_or_production = production;
}

void set_accept_action(Action** action_table, int state, int symbol)
{
    action_table[state][symbol].type = ACCEPT;
}

void set_error_action(Action** action_table, int state, int symbol)
{
    action_table[state][symbol].type = ERROR;
}

void freeActionTable(Action** action_table, int num_state) {
    for (int i = 0; i < num_state; i++) {
        free(action_table[i]);
    }
    free(action_table);
}