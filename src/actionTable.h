#include "enum.h"

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

Action** create_action_table(int num_state, int num_symbol);
void set_shift_action(Action** action_table, int state, int symbol, int next_state);
void set_reduce_action(Action** action_table, int state, int symbol, int production);
void set_accept_action(Action** action_table, int state, int symbol);
void set_error_action(Action** action_table, int state, int symbol);
void freeActionTable(Action** action_table, int num_state);