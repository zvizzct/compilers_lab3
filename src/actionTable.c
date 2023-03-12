#include "actionTable.h" // Including the action table header file
#include <stdlib.h>      // Including the standard library header file

/**
 * @brief Create a new action table with the given number of states and symbols
 * @param num_state (int) the number of states in the action table
 * @param num_symbol (int) the number of symbols in the action table
 * @return Action** a pointer to the new action table
 */
Action **create_action_table(int num_state, int num_symbol)
{
    // Allocate memory for the action table
    Action **action_table = malloc(num_state * sizeof(Action *));
    for (int i = 0; i < num_state; i++)
    {
        action_table[i] = malloc(num_symbol * sizeof(Action));
    }

    // Initialize the action table with default values
    for (int i = 0; i < num_state; i++)
    {
        for (int j = 0; j < num_symbol; j++)
        {
            action_table[i][j].type = ERROR;
            action_table[i][j].state_or_production = -1;
        }
    }
    return action_table; // Return the new action table
}

/**
 * @brief Set a shift action in the action table
 * @param action_table (Action**) the action table to set the action in
 * @param state (int) the state to set the action in
 * @param symbol (int) the symbol to set the action for
 * @param next_state (int) the next state to shift to
 * @return void
 */
void set_shift_action(Action **action_table, int state, int symbol, int next_state)
{
    action_table[state][symbol].type = SHIFT;                     // Set the action type to SHIFT
    action_table[state][symbol].state_or_production = next_state; // Set the next state to shift to
}

/**
 * @brief Set a reduce action in the action table
 * @param action_table (Action**) the action table to set the action in
 * @param state (int) the state to set the action in
 * @param symbol (int) the symbol to set the action for
 * @param production (int) the production to reduce to
 * @return void
 */
void set_reduce_action(Action **action_table, int state, int symbol, int production)
{
    action_table[state][symbol].type = REDUCE;                    // Set the action type to REDUCE
    action_table[state][symbol].state_or_production = production; // Set the production to reduce to
}

/**
 * @brief Set an accept action in the action table
 * @param action_table (Action**) the action table to set the action in
 * @param state (int) the state to set the action in
 * @param symbol (int) the symbol to set the action for
 * @return void
 */
void set_accept_action(Action **action_table, int state, int symbol)
{
    action_table[state][symbol].type = ACCEPT; // Set the action type to ACCEPT
}

/**
 * @brief Set an error action in the action table
 * @param action_table (Action**) the action table to set the action in
 * @param state (int) the state to set the action in
 * @param symbol (int) the symbol to set the action for
 * @return void
 */
void set_error_action(Action **action_table, int state, int symbol)
{
    action_table[state][symbol].type = ERROR; // Set the action type to ERROR
}

/**
 * @brief Free the memory allocated for the action table
 * @param action_table (Action**) the action table to free
 * @param num_state (int) the number of states in the action table
 * @return void
 */
void freeActionTable(Action **action_table, int num_state)
{
    for (int i = 0; i < num_state; i++)
    {
        free(action_table[i]); // Free the memory allocated for each row in the action table
    }
    free(action_table); // Free the memory allocated for the action table itself
}