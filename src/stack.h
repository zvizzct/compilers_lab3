typedef struct
{
    int symbol;
    int state;
} stack_entry;

typedef struct stack
{
    stack_entry entries[100];
    int size;
} stack;


stack_entry pop(stack stack) {

}

void push(stack stack, stack_entry element) {

}

stack_entry getTopStack(stack stack) {
    return stack.entries[stack.size - 1];
}
