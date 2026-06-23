#include "node.h"

Node *newNode(int info) {
    Node *new = (Node *) malloc(sizeof(Node));
    new->info = info;
    new->next = NULL;
    return new;
}