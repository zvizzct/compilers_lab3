#include "actionTable.h"
#include "gotoTable.h"

#if (CASE == THEORY)
production_rule* createProductionRulesTheoryExemple() {
    production_rule* productions = malloc(3*sizeof(production_rule));
    productions[0] = (production_rule){"S", S, "E", 1};
    productions[1] = (production_rule){"E", E, "E+(E)", 5};
    productions[2] = (production_rule){"E", E, "NUM", 1};
    return productions;
}

void setUpTablesTheoryExemple(Action** action_table, int** goto_table)
{
    // State 0
    set_shift_action(action_table, 0, NUM, 1);
    // GOTO
    goto_table[0][E] = 2;

    // State 1
    set_reduce_action(action_table, 1, PLUS, 2);
    set_reduce_action(action_table, 1, ACC, 2);

    // State 2
    set_shift_action(action_table, 2, PLUS, 3);
    set_accept_action(action_table, 2, ACC);

    // State 3
    set_shift_action(action_table, 3, LEFT_PARENTHESIS, 4);

    // State 4
    set_shift_action(action_table, 4, NUM, 5);
    // GOTO
    goto_table[4][E] = 6;

    // State 5
    set_reduce_action(action_table, 5, RIGHT_PARENTHESIS, 2);
    set_reduce_action(action_table, 5, PLUS, 2);

    // State 6
    set_shift_action(action_table, 6, RIGHT_PARENTHESIS, 7);
    set_shift_action(action_table, 6, PLUS, 8);

    // State 7
    set_reduce_action(action_table, 7, PLUS, 1);
    set_reduce_action(action_table, 7, ACC, 1);

    // State 8
    set_shift_action(action_table, 8, LEFT_PARENTHESIS, 9);

    // State 9
    set_shift_action(action_table, 9, NUM, 5);
    // GOTO
    goto_table[9][E] = 10;

    // State 10
    set_shift_action(action_table, 10, RIGHT_PARENTHESIS, 11);
    set_shift_action(action_table, 10, PLUS, 8);

    // State 11
    set_reduce_action(action_table, 11, PLUS, 1);
    set_reduce_action(action_table, 11, RIGHT_PARENTHESIS, 1);
}
#endif

#if (CASE == LAB)
production_rule* createProductionRulesLab() {
    production_rule* productions = malloc(7*sizeof(production_rule));
    // To complete
    productions[0] = (production_rule){"S", S, "E", 1};
    productions[1] = (production_rule){"E", E, "E+T", 3};
    productions[2] = (production_rule){"E", E, "T", 1};
    productions[3] = (production_rule){"T", T, "T*F", 3};
    productions[4] = (production_rule){"T", T, "F", 1};
    productions[5] = (production_rule){"F", F, "(E)", 3};
    productions[6] = (production_rule){"F", F, "NUM", 1};

    return productions;
}

void setUpTablesLab(Action** action_table, int** goto_table)
{
    // State 0
    set_shift_action(action_table, 0, NUM, 6);
    set_shift_action(action_table, 0, LEFT_PARENTHESIS, 10);
    goto_table[0][E] = 1;
    goto_table[0][T] = 8;
    goto_table[0][F] = 9;
    // State 1
    set_shift_action(action_table, 1, PLUS, 2);
    set_accept_action(action_table, 1, ACC);
    // State 2
    set_shift_action(action_table, 2, NUM, 6);
    goto_table[2][T] = 3;
    goto_table[2][F] = 7;
    // State 3
    set_shift_action(action_table, 3, MULT, 4);
    set_reduce_action(action_table, 3, PLUS, 0);
    set_reduce_action(action_table, 3, ACC, 0);
    // State 4
    set_shift_action(action_table, 4, NUM, 6);
    set_shift_action(action_table, 4, LEFT_PARENTHESIS, 10);
    goto_table[4][F] = 5;
    // State 5
    set_reduce_action(action_table, 5, PLUS, 1);
    set_reduce_action(action_table, 5, MULT, 1);
    set_reduce_action(action_table, 5, ACC, 1);
    // State 6
    set_reduce_action(action_table, 6, PLUS, 6);
    set_reduce_action(action_table, 6, MULT, 6);
    set_reduce_action(action_table, 6, ACC, 6);
    // State 7
    set_reduce_action(action_table, 7, PLUS, 4);
    set_reduce_action(action_table, 7, MULT, 4);
    set_reduce_action(action_table, 7, ACC, 4);
    // State 8
    set_shift_action(action_table, 8, PLUS, 4);
    set_reduce_action(action_table, 8, ACC, 2);
    // State 9
    set_reduce_action(action_table, 9, PLUS, 4);
    set_reduce_action(action_table, 9, MULT, 4);
    set_reduce_action(action_table, 9, ACC, 4);
    // State 10
    set_shift_action(action_table, 10, LEFT_PARENTHESIS, 16);
    set_shift_action(action_table, 10, NUM, 22);
    goto_table[10][E] = 11;
    goto_table[10][T] = 19;
    goto_table[10][F] = 20;
    // State 11
    set_shift_action(action_table, 11, PLUS, 13);
    set_shift_action(action_table, 11, RIGHT_PARENTHESIS, 12);
    // State 12
    set_reduce_action(action_table, 12, PLUS, 5);
    set_reduce_action(action_table, 12, MULT, 5);
    set_reduce_action(action_table, 12, ACC, 5);
    // State 13
    set_shift_action(action_table, 13, LEFT_PARENTHESIS, 16);
    set_shift_action(action_table, 13, NUM, 22);
    goto_table[13][T] = 14;
    goto_table[13][F] = 20;
    // State 14
    set_reduce_action(action_table, 14, PLUS, 1);
    set_shift_action(action_table, 14, MULT, 15);
    set_reduce_action(action_table, 14, RIGHT_PARENTHESIS, 1);
    // State 15
    set_shift_action(action_table, 15, LEFT_PARENTHESIS, 16);
    set_shift_action(action_table, 15, NUM, 22);
    goto_table[15][F] = 21;
    // State 16
    set_shift_action(action_table, 16, LEFT_PARENTHESIS, 16);
    set_shift_action(action_table, 16, NUM, 22);
    goto_table[16][E] = 17;
    goto_table[16][T] = 19;
    goto_table[16][F] = 20;
    // State 17
    set_shift_action(action_table, 17, PLUS, 13);
    set_shift_action(action_table, 17, RIGHT_PARENTHESIS, 18);
    // State 18
    set_reduce_action(action_table, 18, PLUS, 5);
    set_reduce_action(action_table, 18, MULT, 5);
    set_reduce_action(action_table, 18, RIGHT_PARENTHESIS, 5);
    // State 19
    set_reduce_action(action_table, 19, PLUS, 2);
    set_shift_action(action_table, 19, MULT, 15);
    set_reduce_action(action_table, 19, RIGHT_PARENTHESIS, 2);
    // State 20
    set_reduce_action(action_table, 20, PLUS, 4);
    set_reduce_action(action_table, 20, MULT, 4);
    set_reduce_action(action_table, 20, RIGHT_PARENTHESIS, 4);
    // State 21
    set_reduce_action(action_table, 21, PLUS, 3);
    set_reduce_action(action_table, 21, MULT, 3);
    set_reduce_action(action_table, 21, RIGHT_PARENTHESIS, 3);
    // State 22
    set_reduce_action(action_table, 22, PLUS, 6);
    set_reduce_action(action_table, 22, MULT, 6);
    set_reduce_action(action_table, 22, RIGHT_PARENTHESIS, 6);
}
#endif