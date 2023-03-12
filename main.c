/*
 * @file main.c
 * @brief Main file for the preprocessor app that calls the other functions to process the file
 * content and save it to a new file.
 */

#include <stdio.h>
#include <stdlib.h>
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
    
    // Get tokens 
    // tokens should be a struc : char* lexeme, char* category later
    int tokens[] = {NUM, PLUS, LEFT_PARENTHESIS,NUM, RIGHT_PARENTHESIS, PLUS, LEFT_PARENTHESIS, NUM, RIGHT_PARENTHESIS, ACC};
    int num_tokens = sizeof(tokens)/sizeof(tokens[0]);

    // Open output files
    FILE *output_file = openFile("output/outputTheory.txt", "w");

    runAutomaton(productions_theory, action_table, goto_table, tokens, num_tokens, output_file);

    // Free the memory space
    freeActionTable(action_table, 12);
    freeGotoTable(goto_table, 12);
    free(productions_theory);
    //free(productions_lab);
    return 0;
}
