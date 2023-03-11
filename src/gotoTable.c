#define NUM_SYMBOLS 6
#define NUM_STATES 20

int goto_table[NUM_STATES][NUM_SYMBOLS];

void init_goto_table()
{
    // initialize the action table
    for (int i = 0; i < NUM_STATES; i++)
    {
        for (int j = 0; j < NUM_SYMBOLS; j++)
        {
            goto_table[i][j] = -1;
        }
    }
    // state 0
    // goto_table[0][0] = 1;
    // To complete
}
