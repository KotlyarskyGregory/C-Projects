#ifndef SINGLY_Linked_List_H
#define SINGLY_Linked_List_H

typedef struct Data
{
    int value;
    int otherValue;
} Data;

typedef struct Node
{
    struct Node *nextNodePointer;
    Data *data;
} Node;

typedef struct List
{
    struct Node *head;
    struct Node *tail;
    int inputsCounter;
} List;


void initList(List *list);

void addToTail(List *list, int input, int otherInput);

void printList(List *list);

#endif