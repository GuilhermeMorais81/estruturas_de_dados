#include "stack.h"

Stack *newStack(int capacity) {
    Stack *new = (Stack *) malloc(sizeof(Stack));
    new->elements = (int *) malloc(sizeof(int) * capacity);
    new->capacity = capacity;
    new->top = 0;
    return new;
}

bool isEmpty(Stack *stack) {
    return stack->top == 0;
}

bool isFull(Stack *stack) {
    return stack->capacity == stack->top;
}

bool push(Stack *stack, int newEl) {
    if(isFull(stack)) return false;
    stack->elements[stack->top++] = newEl;
    return true;
}

bool pop(Stack *stack, int *popped) {
    if(isEmpty(stack)) return false;
    *popped = stack->elements[--stack->top];
    return true;
}

int length(Stack *stack) {
    return stack->top;
}

bool printStack(Stack *stack) {
    if(isEmpty(stack)) return false;
    for(int i = length(stack) - 1; i >= 0; i--) printf("%d | ", stack->elements[i]);
    printf("\n");
    return true;
}

bool freeStack(Stack *stack) {
    if(stack == NULL) return false;
    free(stack->elements);
    free(stack);
    return true;
}