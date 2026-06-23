#include "../../testlib.h"

typedef struct Node {
    int info;
    struct Node * next;
} Node;

Node *newNode(int info);