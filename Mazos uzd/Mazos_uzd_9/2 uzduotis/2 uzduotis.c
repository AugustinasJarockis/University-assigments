#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int size;
    int *ptr;
} Stack;

void initStack(Stack *stack);
void printStack(Stack *stack);
int getStackSize(Stack *stack);
void push(Stack *stack, int value);
int top(Stack *stack);
int pop(Stack *stack);
void destroyStack(Stack *stack);

int main()
{
    Stack stack;
    initStack(&stack);
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 75);
    printf("%d ==== %d\n", top(&stack), getStackSize(&stack));
    push(&stack, 6);
    push(&stack, 7);
    push(&stack, 8);
    push(&stack, 9);
    push(&stack, 10);
    printf("%d ==== %d\n", top(&stack), getStackSize(&stack));
    printStack(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    printf("%d ==== %d\n", top(&stack), getStackSize(&stack));
    destroyStack(&stack);
    printf("%d ==== %d\n", top(&stack), getStackSize(&stack));
    return 0;
}

void initStack(Stack *stack)
{
    (*stack).size = 0;
    (*stack).ptr = NULL;
}

void printStack(Stack *stack)
{
    for(int i = 0; i < (*stack).size; i++)
    {
        printf("%d\n", (*stack).ptr[i]);
    }
}

int getStackSize(Stack *stack)
{
    return (*stack).size;
}

void push(Stack *stack, int value)
{
    (*stack).size++;
    (*stack).ptr = realloc((*stack).ptr, (*stack).size * sizeof(int));
    (*stack).ptr[(*stack).size - 1] = value;
}

int top(Stack *stack)
{
    if((*stack).size == 0)
        return 0;
    return (*stack).ptr[(*stack).size - 1];
}

int pop(Stack *stack)
{
    int last_elem = top(stack);
    (*stack).size--;
    (*stack).ptr = realloc((*stack).ptr, (*stack).size * sizeof(int));
    return last_elem;
}

void destroyStack(Stack *stack)
{
    free((*stack).ptr);
    (*stack).ptr = NULL;
    (*stack).size = 0;
}
