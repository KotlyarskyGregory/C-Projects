#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Data
{
    int inputOne;
    int inputTwo;    
} Data;

typedef struct Node
{
    struct Node *pointerNextNode;
    Data *data;

} Node;

typedef struct List
{
    Node *head;
    Node *tail;
    int nodeCounter;
} List;

void initList(List *myList);

void addToTail(List *myList, int varOne, int varTwo);

void printList(List *myList);

void freeList(List *myList);


#endif