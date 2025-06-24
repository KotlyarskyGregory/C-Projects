#include <stdio.h>
#include "../include/singly_linked_list.h"

int main(void) {
    List testList;

    initList(&testList);

    for (int i = 0; i < 5; i++) {
        addToTail(&testList, i, i+1);
    }

    printList(&testList);

    freeList(&testList);

    return 0;
}