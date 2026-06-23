#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ARR_LENGTH 10

void printVector(int *vector);
void fillVector(int *vector);
void bubbleSort(int *vector);

int main(int argc, char const *argv[])
{
    int *A = (int *) malloc(sizeof(int) * ARR_LENGTH);
    srand(time(0));
    fillVector(A);
    printVector(A);
    bubbleSort(A);
    printf("Sorted vector:\n");
    printVector(A);
    free(A);
    return 0;
}


void printVector(int *vector) {
    for(int i = 0; i < ARR_LENGTH; i++) {
        printf("%d | ", vector[i]);
    }
    printf("\n");
}

void fillVector(int *vector) {
    for(int i = 0; i < ARR_LENGTH; i++) {
        vector[i] = rand() % 10;
    }
}

void bubbleSort(int *vector) {
    for(int i = 1; i < ARR_LENGTH; i++) {
        for(int j = 0; j < ARR_LENGTH - i; j++) {
            if(vector[j] > vector[j + 1]) {
                int temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
}

