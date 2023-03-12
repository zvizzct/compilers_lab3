
/*
 * @file utilsFiles.h
 * @brief File containing the function declarations for file handling
 */

#include <stdio.h>
#include <stdlib.h> //
#include <string.h>

/**
 * @brief Open a file with a provided name
 *
 * @param fileName The name of the file to open
 * @return FILE* Pointer to the opened file, or NULL if the file does not exist or no file name was provided
 */
FILE *openFile(char *fileName, char *openMode)
{
    // Check if fileName is NULL, if it is, print an error message and return NULL
    if (fileName == NULL)
    {
        return NULL;
    }
    // Try to open the file with the given fileName in read mode
    FILE *fptr = fopen(fileName, openMode);

    // If the file doesn't exist, print an error message and return NULL
    if (fptr == NULL)
    {
        printf("Error opening file %s\n", fileName);
        exit(1);
    }
    // If file exists, return the file pointer
    return fptr;
}
/**
 * @brief Creates a new string containing the name of the input file.
 * @param argv The command line argument containing the input file name.
 * @return A pointer to a string containing the name of the input file.
 */
char *getInputFileName(const char *argv)
{
    char *input_file_name = malloc(40 * sizeof(char));
    sprintf(input_file_name, "%s", argv);
    return input_file_name;
}

/**
 * Build the name of the output file from the name of the input file by adding scn at the end
 * @param input_file_name an array of character containing the name of the input file
 * @return output_file_name an array of character with the output file name of the form :
 * input_file_name_p3dbg.txt
 */
char *getOutputFileName(char input_file_name[])
{
    char *output_file_name = malloc(50 * sizeof(char));
    int i;
    for (i = 0; input_file_name[i] != '.'; i++)
    {
        output_file_name[i] = input_file_name[i];
    }
    output_file_name[i] = '_';
    output_file_name[i + 1] = 'p';
    output_file_name[i + 2] = '3';
    output_file_name[i + 3] = 'd';
    output_file_name[i + 4] = 'b';
    output_file_name[i + 5] = 'g';
    output_file_name[i + 6] = '.';
    output_file_name[i + 7] = 't';
    output_file_name[i + 8] = 'x';
    output_file_name[i + 9] = 't';
    output_file_name[i + 10] = '\0';
    return output_file_name;
}
