#include <stdio.h> 
#include <stdlib.h>

typedef struct Token
{
    char* lexeme;
    char* category;
    Token *next;
};

Token createToken(char* lexeme, char* category) {
    Token *token = (Token*) malloc(sizeof(Token));
    token->lexeme = lexeme;
    token->category = category;
    token->next = NULL;
}

typedef struct TokenList
{
    Token *first_token;
    int size;
};

TokenList* initialize() {
    TokenList *tl = (TokenList*) malloc(sizeof(TokenList));
    Token *first_element = (Token*) malloc(sizeof(Token));
    first_element->lexeme = 0;
    first_element->category = 0;
    first_element->next = NULL;
    tl->first_token = first_element;
    tl->size = 0; 
}

void add(TokenList tl, Token t) {
    if (tl.size == 0)
    {
        tl.first_token = &t;
    }
    else
    {
        Token *last_token = tl.first_token;
        while (last_token->next != NULL)
        {
            last_token = last_token->next;
        }
        last_token->next = &t;
    }
}

