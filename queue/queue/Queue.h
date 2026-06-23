#include "../Node/Node.h"

typedef struct Queue {
    Node *head;
    Node *tail;
} Queue;

void newQueue(Queue *queue);
int isEmpty(Queue *queue);
void enqueue(Queue *queue, int newEl);
int dequeue(Queue *queue);
bool printQueue(Queue *queue);
bool freeQueue(Queue *queue);