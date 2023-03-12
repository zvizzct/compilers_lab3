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
    // Initialize productions rules
    production_rule* productions_theory = createProductionRulesTheoryExemple();
    //production_rule* productions_lab = createProductionRulesLab();

    // Initialize tables
    Action** action_table = create_action_table(12, 7);
    int ** goto_table = create_goto_table(12,7);
    //Action** action_table = create_action_table(23, 9);
    //int ** goto_table = create_goto_table(23,9);

    // Set specific parser
    setUpTablesTheoryExemple(action_table, goto_table);
    //setUpTablesLab(action_table, goto_table);
    
    // Setup file names
    char* input_file_name = getInputFileName(argv[1]);
    char* output_file_name = getOutputFileName(input_file_name);

    // Open files
    FILE *input_file = openFile(input_file_name, "r");
    FILE *output_file = openFile(output_file_name, "w");

    // Get tokens 
    Token tokens[250];
    int num_tokens = processInput(input_file, tokens);

    runAutomaton(productions_theory, action_table, goto_table, tokens, num_tokens, output_file);

    // Free the memory space
    freeActionTable(action_table, 12);
    freeGotoTable(goto_table, 12);
    free(productions_theory);
    free(output_file_name);
    free(input_file_name);
    //free(productions_lab);
    fclose(output_file);
    return 0;
}
