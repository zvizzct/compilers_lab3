#include "stack.h"
#include "gotoTable.c"
#include "enum.c"

#define NUM_SYMBOLS 6
#define NUM_STATES 20

typedef struct
{
    enum ActionType type;
    int state_or_production;
} Action;

typedef struct production_rule
{
    int lhs;
    int rhs[6];
    int rhs_len;
} production_rule;

Action action_table[NUM_STATES][NUM_SYMBOLS];

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
void set_shift_action(int state, Symbol symbol, int next_state)
{
    action_table[state][symbol].type = SHIFT;
    action_table[state][symbol].state_or_production = next_state;
}

void set_reduce_action(int state, Symbol symbol, int production)
{
    action_table[state][symbol].type = REDUCE;
    action_table[state][symbol].state_or_production = production;
}

void set_accept_action(int state, Symbol symbol)
{
    action_table[state][symbol].type = ACCEPT;
}

void set_error_action(int state, Symbol symbol)
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
