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