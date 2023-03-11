#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKEN_LEN 256
#define MAX_NUM_TOKENS 1000

typedef struct token
{
    char lexeme[MAX_TOKEN_LEN];
    char type[MAX_TOKEN_LEN];
} token_t;

token_t tokens[MAX_NUM_TOKENS];

int main()
{
    FILE *fp;
    char line[MAX_TOKEN_LEN];
    char *lexeme;
    char *type;
    int i = 0;

    fp = fopen("tokens.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, MAX_TOKEN_LEN, fp) != NULL)
    {
        lexeme = strtok(line, ",<>");
        type = strtok(NULL, ",<> \n");

        strcpy(tokens[i].lexeme, lexeme);
        strcpy(tokens[i].type, type);

        i++;
    }

    fclose(fp);

    for (int j = 0; j < i; j++)
    {
        printf("%s, %s\n", tokens[j].lexeme, tokens[j].type);
    }

    return 0;
}