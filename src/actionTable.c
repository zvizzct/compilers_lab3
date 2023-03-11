#include "actionTable.h"

void init_action_table()
{
    // initialize the action table
    for (int i = 0; i < NUM_STATES; i++)
    {
        for (int j = 0; j < NUM_SYMBOLS; j++)
        {
            action_table[i][j].type = ERROR;
            action_table[i][j].state_or_production = -1;
        }
    }
}
void set_shift_action(int state, int symbol, int next_state)
{
    action_table[state][symbol].type = SHIFT;
    action_table[state][symbol].state_or_production = next_state;
}

void set_reduce_action(int state, int symbol, int production)
{
    action_table[state][symbol].type = REDUCE;
    action_table[state][symbol].state_or_production = production;
}

void set_accept_action(int state, int symbol)
{
    action_table[state][symbol].type = ACCEPT;
}

void set_error_action(int state, int symbol)
{
    action_table[state][symbol].type = ERROR;
}

void reduce(production_rule production, Stack stack)
{
    StackElement popped;
    for (int i = 0; i < production.rhs_len; i++)
    {
        popped = pop(&stack);
    }
    int new_current_state = getStackTopState(stack);
    int new_state = goto_table[new_current_state][production.lhs];
    StackElement new_element = {production.lhs, new_state};
    push(&stack, new_element);
}

void shift(Stack stack, int token, int next_state)
{
    StackElement new_element = {token, next_state};
    push(&stack, new_element);
}
