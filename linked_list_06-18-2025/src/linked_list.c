#include <stdio.h>
#include <stdlib.h>
#include "../include/linked_list.h"

void initList(List *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return;
 }

void addToEndList(List *list, int data) {
    LinkedList *newNode = (LinkedList*) malloc(sizeof(LinkedList));
    if (newNode == NULL) {
        printf("Error in new node allocation\n");
        return;
    }

    Data *newData = (Data*) malloc(sizeof(Data));
    if (newData == NULL) {
        printf("Error in new data allocation\n");
        return;
    }

    newData->dataValue = data;

    if (list->tail != NULL) {
        
    }
}