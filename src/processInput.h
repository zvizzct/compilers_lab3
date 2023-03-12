#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "enum.h"

#define MAX_TOKEN_LEN 256

typedef struct token
{
    char lexeme[MAX_TOKEN_LEN];
    char type[MAX_TOKEN_LEN];
    int index;
} Token;


int processInput(FILE* input_file, Token *tokens)
{
    char line[MAX_TOKEN_LEN];
    char *pos;
    int i = 0;


    while (fgets(line, MAX_TOKEN_LEN, input_file) != NULL)
    {
        // Extract tokens from the line
        pos = line;
        while (*pos != '\0')
        {
            // Skip delimiters
            pos += strspn(pos, " \t\n<>,");

            // Extract lexeme
            int lexeme_len = strcspn(pos, "<,>");
            if (lexeme_len > 0) {
                strncpy(tokens[i].lexeme, pos, lexeme_len);
                tokens[i].lexeme[lexeme_len] = '\0';
                pos += lexeme_len;
                
                // Skip delimiters
                pos += strspn(pos, "<,>");

                // Extract type
                int type_len = strcspn(pos, "<,>\n");
                strncpy(tokens[i].type, pos, type_len);
                tokens[i].type[type_len] = '\0';
                pos += type_len;

                // Get index
                if (strcmp(tokens[i].type, "CAT_NUMBER") == 0) tokens[i].index = NUM;
                else if (strcmp(tokens[i].lexeme, "+") == 0) tokens[i].index = PLUS;
                else if (strcmp(tokens[i].lexeme, "(") == 0) tokens[i].index = LEFT_PARENTHESIS;
                else if (strcmp(tokens[i].lexeme, ")") == 0) tokens[i].index = RIGHT_PARENTHESIS;

                // Skip delimiters
                pos += strspn(pos, "<,>");
                
                i++;
            }
        }
    }
    strcpy(tokens[i].lexeme, "$");
    strcpy(tokens[i].type, "CAT_ESPECIAL_CHARACTER");
    tokens[i].index = ACC;
    i++;
    
    fclose(input_file);
    return i;
}