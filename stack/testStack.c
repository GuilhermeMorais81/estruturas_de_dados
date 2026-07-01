#include "stack.h"
#include "../testlib.h"
#include <time.h>



void selectOption(int option, Stack *stackA);

int main(int argc, char const *argv[])
{
    explainOptions();
    Stack *stackA;
    srand(time(0)); 
    stackA = newStack(20);
    int option = 3;
    while(option != 0) {
        option = receiveInput();
        selectOption(option, stackA);
        printStack(stackA);
    }
    freeStack(stackA);
    return 0;
}

int receiveInput() {
    int input;
    scanf("%d", &input);
    return input;
}

void selectOption(int option, Stack *stackA) {
    int popped;
    switch(option) {
        case 1:
            if(!push(stackA, rand() % 10)) printf("Is Full...\n");
        break;
        case 2:
            if(pop(stackA, &popped)) printf(COLOR_GREEN"%d Was Popped\n"COLOR_RESET, popped);
            else printf("Is empty...\n");
        default:
        break;
    }
}

void explainOptions() {
    printf("|---> Select 1 to push an element\n");
    printf("|---> Select 2 to pop an element\n");
    printf("|---> Select 0 to exit\n");
}
