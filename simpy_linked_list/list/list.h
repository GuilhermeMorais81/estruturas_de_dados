#include "../node/node.h"

typedef struct List {
    Node *head;
} List;

List *newList();
bool isEmpty(List *list);
void addFirst(List *list, int newEL);
void addEnd(List *list, int newEl);
int removeFirst(List *list);
int removeEnd(List *list);
bool printList(List *list);
bool removeByValue(List *list, int target);
bool isFirstValue(List *list, int target);
bool isLastValue(List *list, int target);
bool freeList(List *list);