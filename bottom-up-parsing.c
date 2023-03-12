/*
 * @file main.c
 * @brief Main file for the preprocessor app that calls the other functions to process the file
 * content and save it to a new file.
 */

#include <unistd.h>
#include "src/utilsFiles.c"
#include "src/automaton.h"

int main(int argc, char const *argv[])
{
    // Initialize productions rules and parsing table
#if (CASE == THEORY)
    production_rule* productions = createProductionRulesTheoryExemple();
    Action** action_table = create_action_table(12, 7);
    int ** goto_table = create_goto_table(12,7);
    setUpTablesTheoryExemple(action_table, goto_table);
#endif
#if (CASE == LAB)
    production_rule* productions = createProductionRulesLab();
    Action** action_table = create_action_table(23, 10);
    int ** goto_table = create_goto_table(23,10);
    setUpTablesLab(action_table, goto_table);
#endif
    
    // Setup file names
    char* input_file_name = getInputFileName(argv[1]);
    char* output_file_name = getOutputFileName(input_file_name);

    // Open files
    FILE *input_file = openFile(input_file_name, "r");
    FILE *output_file = openFile(output_file_name, "w");

    // Get tokens 
    Token tokens[250];
    int num_tokens = processInput(input_file, tokens);

    runAutomaton(productions, action_table, goto_table, tokens, num_tokens, output_file);

    // Free the memory space
    freeActionTable(action_table, 12);
    freeGotoTable(goto_table, 12);
    free(productions);
    free(output_file_name);
    free(input_file_name);
    fclose(output_file);
    return 0;
}
