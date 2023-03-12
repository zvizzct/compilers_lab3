#include "stack.h"

enum Symbol {
    S,
    E,
    T,
    F,
    PLUS,
    MULT,
    LEFT_PARENTHESIS,
    RIGHT_PARENTHESIS,
    NUM,
};
typedef struct production_rule
{
    int lhs;
    int rhs[6];
    int rhs_len;
} production_rule;

production_rule* initProductions() {
    production_rule productions[7] = {{S, {E}, 1}, {E, {E,PLUS,T}, 3}, {E, {T}, 1}};
}

void reduce(production_rule production, stack stack) {
    for (int i = 0; i < production.rhs_len; i++)
    {
        pop(stack);
    }
    int new_current_state = getStackTopState(stack);
    int new_state = goto_table[new_current_state][production.lhs];
    stack_entry new_element = {production.lhs, new_state};
    push(stack, new_element);
}

void shift(stack stack, int token, int next_state) {
    
}