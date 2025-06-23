#include <stdio.h>
#include "../include/doubly_linked_list.h"

int main(void) {
    List testList;

    initList(&testList);

    for (int i = 0; i < 5; i++) {
        addToTail(&testList, i, i % 3);
    }

    printf("List forward:\n");
    printListForward(&testList);
    printf("\n");

    printf("List reverse:\n");
    printListReverse(&testList);
    printf("\n");

    return 0;
}
