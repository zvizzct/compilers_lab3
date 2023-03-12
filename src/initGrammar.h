#include "actionTable.h"
#include "gotoTable.h"

production_rule* createProductionRulesTheoryExemple() {
    production_rule* productions = malloc(3*sizeof(production_rule));
    productions[0] = (production_rule){S, {E}, 1};
    productions[1] = (production_rule){E, {E, PLUS, LEFT_PARENTHESIS, E, RIGHT_PARENTHESIS}, 5};
    productions[2] = (production_rule){E, {NUM}, 1};
    return productions;
}

production_rule* createProductionRulesLab() {
    production_rule* productions = malloc(7*sizeof(production_rule));
    // To complete
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

// void setUpTablesLab(Action** action_table, int** goto_table)
// {
//     // State 0
//     set_shift_action(action_table, 0, NUM, 6);
//     set_shift_action(action_table, 0, LEFT_PARENTHESIS, 10);
//     goto_table[0][E] = 1;
//     goto_table[0][T] = 8;
//     goto_table[0][F] = 9;

//     // State 1
//     set_shift_action(action_table, 1, PLUS, 2);
//     set_accept_action(action_table, 1, ACC);

//     // State 2
//     set_shift_action(action_table, 2, NUM, 6);
//     goto_table[2][T] = 3;
//     goto_table[2][F] = 7;

//     // State 3
//     set_shift_action(action_table, 3, MULT, 4);
//     set_reduce_action(action_table, 3, PLUS, 0);
//     set_reduce_action(action_table, 3, ACC, 0);

//     // State 4
//     set_shift_action(action_table, 4, NUM, 6);
//     set_shift_action(action_table, 4, LEFT_PARENTHESIS, 10);
//     goto_table[4][F] = 5;

//     // State 5
//     set_reduce_action(action_table, 5, MULT, 1);
// }
