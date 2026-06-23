#include "list/list.h"
#include "../testlib.h"

void selectOption(int option, List *listA);
int selectTarget();

int main(int argc, char const *argv[])
{
    explainOptions();
    List *listA;
    srand(time(0));
    int option = 6;
    listA = newList();
    while(option != 0) {
        option = receiveInput();
        selectOption(option, listA);
        printList(listA);
    }
    freeList(listA);
    return 0;
}

int receiveInput() {
    int input;
    scanf("%d", &input);
    return input;
}

void selectOption(int option, List *listA) {
    switch(option) {
        case 1:
            addFirst(listA, rand() % 10);
            break;
        case 2:
            addEnd(listA, rand() % 10);
            break;
        case 3:
            if(!isEmpty(listA)) printf(COLOR_GREEN"%d was removed first\n"COLOR_RESET, removeFirst(listA));
            else printf(COLOR_GREEN"EMPTY"COLOR_RESET);
            break;
        case 4:
            if(!isEmpty(listA)) printf(COLOR_GREEN"%d was removed End\n"COLOR_RESET, removeEnd(listA));
            else printf(COLOR_GREEN"EMPTY\n"COLOR_RESET);
            break;
        case 5:
            int target = selectTarget();
            if(removeByValue(listA, target)) printf(COLOR_GREEN"%d was removed\n"COLOR_RESET, target);
            else printf(COLOR_GREEN"Not Found...\n"COLOR_RESET);
            break;
        default:
            break;
    }
}

int selectTarget() {
    int input;
    printf("Select the target to be removed: ");
    scanf("%d", &input);
    return input;
}


void explainOptions() {
    printf("|---> Select 1 to add an element at first\n");
    printf("|---> Select 2 to add an element at the end\n");
    printf("|---> Select 3 to remove at first\n");
    printf("|---> Select 4 to remove the last element\n");
    printf("|---> Select 5 to remove an element by its value\n");
    printf("|---> Select 0 to exit\n");
}
