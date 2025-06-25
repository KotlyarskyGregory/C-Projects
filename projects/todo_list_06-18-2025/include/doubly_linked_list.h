#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct Data 
{
    /*
    To be filled in by applicable data
    */
} Data;

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

void addToTail(List *myList, const Data *data);

void removeNode(List *myList, Node *removeNode);

void clearList(List *myList);

#endif