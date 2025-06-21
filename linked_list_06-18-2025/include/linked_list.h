#ifndef Linked_List_H
#define Linked_List_H

typedef struct LinkedList LinkedList;

typedef struct
{
 int dataValue;

} Data;

typedef struct 
{
    LinkedList *previousNode;
    LinkedList *nextNode;
    Data *data;
} LinkedList;

typedef struct 
{
    LinkedList *head;
    LinkedList *tail;
    int size;
} List;

#endif