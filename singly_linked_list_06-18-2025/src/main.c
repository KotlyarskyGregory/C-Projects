#include <stdio.h>
#include <stdlib.h>
#include "../include/singly_linked_list.h"

int main(void) {
    List myList;

    initList(&myList);
    
    for (int i = 0; i < 5; i++) {
        addToTail(&myList, i, i + 1);
    }

    printList(&myList);

    return 0;
    
}