#include "enum.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100
#define MAX_STR_LENGTH 50

typedef struct
{
    char symbol[20];
    int state;
} StackElement;

typedef struct
{
    StackElement data[MAX_SIZE];
    int top;
} Stack;

void init(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, StackElement *item);
StackElement pop(Stack *s);
StackElement peek(Stack *s);
StackElement* createStackElement(char symbol[], int state);
void printStack(Stack stack, FILE* output_file);

#endif // STACK_H
