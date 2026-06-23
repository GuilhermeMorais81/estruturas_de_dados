#include "../testlib.h"

typedef struct Stack {
    int *elements;
    int capacity;
    int top;
} Stack;

Stack *newStack(int capacity);
bool isEmpty(Stack *stack);
bool isFull(Stack *stack);
bool push(Stack *stack, int newEl);
bool pop(Stack *stack, int *popped);
int length(Stack *stack);
bool printStack(Stack *stack);