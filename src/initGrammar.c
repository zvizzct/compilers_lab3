
#include "actionTable.c"
#include "gotoTable.c"

void setUpTables()
{
    // State 0
    set_shift_action(0, NUM, 1);
    // GOTO
    goto_table[0][E] = 2;

    // State 1
    set_reduce_action(1, PLUS, 2);
    set_reduce_action(1, ACC, 2);

    // State 2
    set_shift_action(2, PLUS, 3);
    set_accept_action(2, ACC);

    // State 3
    set_shift_action(3, LEFT_PARENTHESIS, 4);

    // State 4
    set_shift_action(4, NUM, 5);
    // GOTO
    goto_table[4][E] = 6;

    // State 5
    set_reduce_action(5, RIGHT_PARENTHESIS, 2);
    set_reduce_action(5, PLUS, 2);

    // State 6
    set_shift_action(6, RIGHT_PARENTHESIS, 7);
    set_shift_action(6, PLUS, 8);

    // State 7
    set_reduce_action(7, PLUS, 1);
    set_reduce_action(7, ACC, 1);

    // State 8
    set_shift_action(8, LEFT_PARENTHESIS, 9);

    // State 9
    set_shift_action(9, NUM, 5);
    // GOTO
    goto_table[9][E] = 10;

    // State 10
    set_shift_action(10, RIGHT_PARENTHESIS, 11);
    set_shift_action(10, PLUS, 8);

    // State 11
    set_reduce_action(11, PLUS, 1);
    set_reduce_action(11, RIGHT_PARENTHESIS, 1);
}

void setUpTables_lab()
{
    // State 0
    set_shift_action(0, NUM, 6);
    set_shift_action(0, LEFT_PARENTHESIS, 10);
    goto_table[0][E] = 1;
    goto_table[0][T] = 8;
    goto_table[0][F] = 9;

    // State 1
    set_shift_action(1, PLUS, 2);
    set_accept_action(1, ACC);

    // State 2
    set_shift_action(2, NUM, 6);
    goto_table[2][T] = 3;
    goto_table[2][F] = 7;

    // State 3
    set_shift_action(3, MULT, 4);
    set_reduce_action(3, PLUS, 0);
    set_reduce_action(3, ACC, 0);

    // State 4
    set_shift_action(4, NUM, 6);
    set_shift_action(4, LEFT_PARENTHESIS, 10);
    goto_table[4][F] = 5;

    // State 5
    set_reduce_action(5, MULT, 1);
}
