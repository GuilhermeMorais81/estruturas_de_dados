#include "Queue.h"

void newQueue(Queue *queue) {
    queue->head = NULL;
    queue->tail = NULL;
}

int isEmpty(Queue *queue) {
    return queue->head == NULL;
}

void enqueue(Queue *queue, int newEl) {
    Node *new = newNode(newEl);
    if(isEmpty(queue)) queue->head = new;
    else queue->tail->next = new;
    queue->tail = new;
}

int dequeue(Queue *queue) {
    Node *adressC = queue->head;
    int infoC = queue->head->info;
    queue->head = queue->head->next;
    if(queue->head == NULL) queue->tail = NULL;
    free(adressC);
    return infoC;
}

bool printQueue(Queue *queue) {
    if(isEmpty(queue)) return false;
    Node *runner = queue->head;
    while(runner != NULL) {
        printf("%d -> ", runner->info);
        runner = runner->next;
    }
    printf("NULL\n");
    return true;
}

bool freeQueue(Queue *queue) {
    if(isEmpty(queue)) return false;
    Node * runner = queue->head;
    Node *target;
    while(runner != NULL) {
        target = runner;
        runner = runner->next;
        free(target);
    }
    free(queue);
    return true;
}