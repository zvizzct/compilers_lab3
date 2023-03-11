
// #include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "enum.c"

#define MAX_SIZE 100
#define MAX_STR_LENGTH 50

typedef struct
{
    Symbol symbol; // TODO change this to a enum
    int num;
} StackElement;

typedef struct
{
    StackElement data[MAX_SIZE];
    int top;
} Stack;

/**
 * Initialize the stack
 * @param s the stack to be initialized
 * @return void
 */
void init(Stack *s)
{
    s->top = -1;
}

/**
 * Check if the stack is empty
 * @param s the stack to be checked
 * @return int 1 if the stack is empty, 0 otherwise
 */
int isEmpty(Stack *s)
{
    return (s->top == -1);
}

/**
 * Check if the stack is full
 * @param s the stack to be checked
 * @return int 1 if the stack is full, 0 otherwise
 */
int isFull(Stack *s)
{
    return (s->top == MAX_SIZE - 1);
}

/**
 * Add an item to the stack
 * @param s the stack to add the item to
 * @param item the item to be added to the stack
 * @return void
 */
void push(Stack *s, StackElement item)
{
    if (isFull(s))
    {
        printf("Stack overflow\n");
        return;
    }
    s->top++;
    s->data[s->top] = item;
}

/**
 * Remove and return the top item from the stack
 * @param s the stack to remove the item from
 * @return StackElement the removed item from the top of the stack
 */
StackElement pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow\n");
        StackElement empty = {"", -1};
        return empty;
    }
    StackElement item = s->data[s->top];
    s->top--;
    return item;
}

/**
 * Return the top item from the stack without removing it
 * @param s the stack to retrieve the top item from
 * @return StackElement the item at the top of the stack
 */
StackElement peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        StackElement empty = {"", -1};
        return empty;
    }
    return s->data[s->top];
}
