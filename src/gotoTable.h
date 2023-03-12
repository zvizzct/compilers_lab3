/**
 * @brief Allocate memory for the goto table and initialize it
 * @param num_state (int) the number of states in the goto table
 * @param num_symbol (int) the number of symbols in the goto table
 * @return int** a pointer to the allocated memory for the goto table
 */
int **create_goto_table(int num_state, int num_symbol)
{
    // Allocate the memory for the goto table
    int **goto_table = malloc(num_state * sizeof(Action *));
    for (int i = 0; i < num_state; i++)
    {
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

/**
 * @brief Free the memory allocated for the goto table
 * @param goto_table (int**) the goto table to free
 * @param num_state (int) the number of states in the goto table
 * @return void
 */
void freeGotoTable(int **goto_table, int num_state)
{
    for (int i = 0; i < num_state; i++)
    {
        free(goto_table[i]); // Free the memory allocated for each row in the goto table
    }
    free(goto_table); // Free the memory allocated for the goto table itself
}
