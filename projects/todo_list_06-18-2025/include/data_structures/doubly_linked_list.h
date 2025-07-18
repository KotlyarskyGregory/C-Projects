#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "../user_input/data.h"

typedef struct Node
{
    Data *data;
    struct Node *pointerNextNode;
    struct Node *pointerPrevNode;

} Node;

typedef struct List
{
    Node *head;
    Node *tail;
    int counterVar;

} List;

void initList(List *myList);

void addToTail(List *myList);

void removeNode(List *myList, Node *removeNode);

void printList(List *mylist);

void clearList(List *myList);

#endif