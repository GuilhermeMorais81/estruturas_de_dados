#include "list.h"

List *newList() {
    List *new = (List *) malloc(sizeof(List));
    new->head = NULL;
    return new;
}

bool isEmpty(List *list) {
    return list->head == NULL;
}

void addFirst(List *list, int newEL) {
    Node *new  = newNode(newEL);
    if(!isEmpty(list)) new->next = list->head;
    list->head = new;
}

void addEnd(List *list, int newEl) {
    Node *new = newNode(newEl);
    if(isEmpty(list)) list->head = new;
    else {
        Node *runner = list->head;
        while(runner->next != NULL) runner = runner->next;
        runner->next = new;
    }
}

int removeFirst(List *list) {
    int infoC = list->head->info;
    Node *adressC = list->head;
    list->head = list->head->next;
    free(adressC);
    return infoC;
}

int removeEnd(List *list) {
    int infoC;
    Node *adressC;
    if(list->head->next == NULL) {
        infoC = list->head->info;
        adressC = list->head;
        list->head = NULL;
    }
    else {
        Node *runner = list->head;
        while(runner->next->next != NULL) runner = runner->next;
        infoC = runner->next->info;
        adressC = runner->next;
        runner->next = NULL;
    }
    free(adressC);
    return infoC;
}

bool printList(List *list) {
    if(isEmpty(list)) return false;
    else {
        Node *runner = list->head;
        while(runner != NULL) {
            printf("%d -> ", runner->info);
            runner = runner->next;
        }
        printf("NULL \n");
        return true;
    }
}

bool removeByValue(List *list, int target) {
    if(isEmpty(list)) return false;
    if(isFirstValue(list, target)) return true;
    if(isLastValue(list, target)) return true;
    Node *runner = list->head->next;
    Node *watchman = list->head;
    while(runner->next != NULL) {
        if(runner->info == target) {
            watchman->next = runner->next;
            free(runner);
            return true;
        }
        watchman = runner;
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
    Node *runner = list->head;
    while(runner->next != NULL) runner = runner->next;
    if(runner->info == target) {
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