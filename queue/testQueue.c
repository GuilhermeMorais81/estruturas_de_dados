#include "queue/Queue.h"
#include "../testlib.h"

void selectOption(int option, Queue *queueA);

int main(int argc, char const *argv[])
{
    explainOptions();
    srand(time(0));
    int option = 3;
    Queue *queueA;
    newQueue(queueA);
    while(option != 0) {
        option = receiveInput();
        selectOption(option, queueA);
        printQueue(queueA);
    }
    return 0;
}

void selectOption(int option, Queue *queueA) {
    switch(option) {
        case 1:
            enqueue(queueA, rand() % 10);
            break;
        case 2:
            if(!isEmpty(queueA)) printf(COLOR_GREEN"%d was removed: \n"COLOR_RESET, dequeue(queueA));
            else printf(COLOR_GREEN"Empty...\n"COLOR_RESET);
            break;
        default:
            break;
    }
}

int receiveInput() {
    int option;
    scanf("%d", &option);
    return option;
}

void explainOptions() {
    printf("|---> Select 1 to enqueue\n");
    printf("|---> Select 2 to dequeue\n");
    printf("|---> Select 0 to exit\n");
}

