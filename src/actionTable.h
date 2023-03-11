#include "stack.h"
#include "enum.h"
#include "gotoTable.c"

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

void init_action_table();

void set_shift_action(int state, int symbol, int next_state);
void set_reduce_action(int state, int symbol, int production);
void set_accept_action(int state, int symbol);
void set_error_action(int state, int symbol);
void reduce(production_rule production, Stack stack);
void shift(Stack stack, int token, int next_state);
