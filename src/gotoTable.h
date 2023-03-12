int** create_goto_table(int num_state, int num_symbol)
{
    // Allocate the memory for the goto table
    int** goto_table = malloc(num_state * sizeof(Action*));
    for (int i = 0; i < num_state; i++) {
        goto_table[i] = malloc(num_symbol * sizeof(Action));
    }
     // initialize the goto table
    for (int i = 0; i < num_state; i++)
    {
        for (int j = 0; j < num_symbol; j++)
        {
            goto_table[i][j] = -1;
        }
    }
    return goto_table;
}

void freeGotoTable(int** goto_table, int num_state) {
    for (int i = 0; i < num_state; i++) {
        free(goto_table[i]);
    }
    free(goto_table);
}
