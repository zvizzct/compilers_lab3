#include "stack.h"

/**
 * @brief Initialize the stack
 * @param s the stack to be initialized
 * @return void
 */
Stack *createStack()
{
    Stack *s = malloc(sizeof(Stack));
    s->top = -1;
    StackElement *initial_element = createStackElement("_", 0);
    push(s, initial_element);
    return s;
}

/**
 * @brief Check if the stack is empty
 * @param s the stack to be checked
 * @return int 1 if the stack is empty, 0 otherwise
 */
int isEmpty(Stack *s)
{
    return (s->top == -1);
}

/**
 * @brief Check if the stack is full
 * @param s the stack to be checked
 * @return int 1 if the stack is full, 0 otherwise
 */
int isFull(Stack *s)
{
    return (s->top == MAX_SIZE - 1);
}

/**
 * @brief Add an item to the stack
 * @param s the stack to add the item to
 * @param item the item to be added to the stack
 * @return void
 */
void push(Stack *s, StackElement *item)
{
    if (isFull(s))
    {
        printf("Stack overflow\n");
        return;
    }
    s->top++;
    s->data[s->top] = *item;
}

/**
 * @brief Remove and return the top item from the stack
 * @param s the stack to remove the item from
 * @return StackElement the removed item from the top of the stack
 */
StackElement pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow\n");
        StackElement *empty = createStackElement("_", -1);
        return *empty;
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
        StackElement *empty = createStackElement("_", -1);
        return *empty;
    }
    return s->data[s->top];
}

StackElement *createStackElement(char symbol[], int state)
{
    StackElement *new_element = malloc(sizeof(new_element));
    strcpy(new_element->symbol, symbol);
    new_element->state = state;
    return new_element;
}

void printStack(Stack stack, FILE *output_file)
{
    fprintf(output_file, "|     ");
    for (int i = 0; i <= stack.top; i++)
    {
        fprintf(output_file, "<%s,%d> ", stack.data[i].symbol, stack.data[i].state);
    }
    fprintf(output_file, "\n");
}
