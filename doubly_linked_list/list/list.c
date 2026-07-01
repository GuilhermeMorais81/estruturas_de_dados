#include "list.h"

List *newList() {
    List *new = (List *) malloc(sizeof(List));
    new->head = NULL;
    new->tail = NULL;
    return new;
}

bool isEmpty(List *list) {
    return list->head == NULL;
}

void addFirst(List *list, int newEL) {
    Node *new = newNode(newEL);
    if(isEmpty(list)) list->tail = new;
    else {
        list->head->before = new;
        new->next = list->head;
    }
    list->head = new;
}

void addEnd(List *list, int newEl) {
    Node *new = newNode(newEl);
    if(isEmpty(list)) list->head = new;
    else {
        list->tail->next = new;
        new->before = list->tail;
    }
    list->tail = new;
}

int removeFirst(List *list) {
    int infoC = list->head->info;
    Node *adressC = list->head;
    list->head = list->head->next;
    if(list->head == NULL) list->tail = NULL;
    else list->head->before = NULL;
    free(adressC);
    return infoC;
}

int removeEnd(List *list) {
    int infoC = list->tail->info;
    Node *adressC = list->tail;
    list->tail = list->tail->before;
    if(list->tail == NULL) list->head = NULL;
    else list->tail->next = NULL;
    free(adressC);
    return infoC;
}

bool printList(List *list) {
    if(isEmpty(list)) return false;
    Node *runner = list->head;
    printf("NULL == ");
    while(runner != NULL) {
        printf("%d == ", runner->info);
        runner = runner->next;
    }
    printf("NULL\n");
    return true;
}

bool removeByValue(List *list, int target) {
    if(isEmpty(list)) return false;
    if(isFirstValue(list, target)) return true;
    if(isLastValue(list, target)) return true;
    Node *runner = list->head->next;
    while(runner->next != NULL) {
        if(runner->info == target) {
            runner->before->next = runner->next;
            runner->next->before = runner->before;
            free(runner);
            return true;
        }
        runner = runner->next;
    }
    return false;
}

bool isFirstValue(List *list, int target) {
    if(list->head->info == target) {
        removeFirst(list);
        return true;
    }
    return false;
}

bool isLastValue(List *list, int target) {
    if(list->tail->info == target) {
        removeEnd(list);
        return true;
    }
    return false;
}

bool freeList(List *list) {
    if(list == NULL) return false;
    Node *runner = list->head;
    Node *target;
    while(runner != NULL) {
        target = runner;
        runner = runner->next;
        free(target);
    }
    free(list);
    return true;
}