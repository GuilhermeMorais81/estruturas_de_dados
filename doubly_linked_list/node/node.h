#include "../../testlib.h"

typedef struct Node {
    int info;
    struct Node *next;
    struct Node *before;
} Node;

Node *newNode(int info);