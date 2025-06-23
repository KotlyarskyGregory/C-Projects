#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct Data
{
    int storeValue;
    int storeIndex;
} Data;

typedef struct Node
{
    struct Node *nextNodePointer;
    struct Node *prevNodePointer;
    Data *data;
} Node;

typedef struct List
{
    Node *head;
    Node *tail;
    int counterVar;
} List;

void initList(List *myList);

void addToTail(List *myList, const int inputVal, const int index);

void printListForward(List *myList);

void printListReverse(List *myList);

#endif