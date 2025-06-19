#include <stdio.h>
#include <stdlib.h>
#include "../include/linked_list.h"

void initList(LinkedList *list) {
    list->previousNode = NULL;
    list->nextNode = NULL;
    
    return;
 }

void addToList(LinkedList *list, int data) {
    Data *dataValue = (Data*) malloc(sizeof(*dataValue));
}