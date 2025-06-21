#ifndef Linked_List_H
#define Linked_List_H

typedef struct 
{
    int data;
} Data;

typedef struct 
{
    struct Node *nextNodePointer;
    struct Data *data;
} Node;

void initList(Node *node);

void addToTail(Node *node, int input);

#endif