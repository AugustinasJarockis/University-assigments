#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point
{
    double x, y;
} Point;

typedef struct Stack
{
    int size;
    Point *ptr;
} Stack;

//Stack
void initStack(Stack *stack);
void printStack(Stack *stack);
int getStackSize(Stack *stack);
void push(Stack *stack, Point value);
Point top(Stack *stack);
Point pop(Stack *stack);
void destroyStack(Stack *stack);
//Point
void printPoint(Point p);
Point createPoint(double x, double y);
double getDistance(Point a, Point b);

int main()
{
    Stack stack;
    initStack(&stack);
    push(&stack, createPoint(12.0, 5.0));
    push(&stack, createPoint(3.0, 4.0));
    push(&stack, createPoint(8.0, 6.0));
    push(&stack, createPoint(12.0, 9.0));
    push(&stack, createPoint(18.0, 13.0));
    printStack(&stack);
    destroyStack(&stack);
    return 0;
}

//Stack
void initStack(Stack *stack)
{
    (*stack).size = 0;
    (*stack).ptr = NULL;
}

void printStack(Stack *stack)
{
    for(int i = 0; i < (*stack).size; i++)
    {
        printPoint((*stack).ptr[i]);
        printf("Distante to origin: %f\n", getDistance((*stack).ptr[i], createPoint(0.0, 0.0)));
    }
}

int getStackSize(Stack *stack)
{
    return (*stack).size;
}

void push(Stack *stack, Point value)
{
    (*stack).size++;
    (*stack).ptr = realloc((*stack).ptr, (*stack).size * sizeof(Point));
    (*stack).ptr[(*stack).size - 1] = value;
}

Point top(Stack *stack)
{
    if((*stack).size == 0)
        return createPoint(-1.123581321, -1.123581321);
    return (*stack).ptr[(*stack).size - 1];
}

Point pop(Stack *stack)
{
    Point last_elem = top(stack);
    (*stack).size--;
    (*stack).ptr = realloc((*stack).ptr, (*stack).size * sizeof(Point));
    return last_elem;
}

void destroyStack(Stack *stack)
{
    free((*stack).ptr);
    (*stack).ptr = NULL;
    (*stack).size = 0;
}
//Point
void printPoint(Point p)
{
    printf("(%f, %f)\n", p.x, p.y);
}

Point createPoint(double x, double y)
{
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

double getDistance(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
