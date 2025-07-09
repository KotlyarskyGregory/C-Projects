#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/history.h"

void initHistory(History* history, int initialCapacity) {
    history->entries = malloc(sizeof(char*) * initialCapacity);
    history->currentCapacity = initialCapacity;
    history->itemCount = 0;
    
    return;
}

void addToHistory(History *history, const char *entry) {
    if (history->itemCount == history->currentCapacity) {
        history->entries = realloc(history->entries, 
            sizeof(char*) * history->currentCapacity * 2
        );
            history->currentCapacity *= 2;
    } 
    
    history->entries[history->itemCount] = malloc(strlen(entry) + 1);

    if (history->entries[history->itemCount] != NULL) {
        strcpy(history->entries[history->itemCount], entry);
    }
    
    history->itemCount++;
    return;
    
}

void getHistory(const History *history) {
    for (int i = 0; i < history->itemCount; i++) {
        printf("%s\n", history->entries[i]);
    }
    
    return;
}

void freeHistory(History *history) {
    for (int i = 0; i < history->itemCount; i++) {
        free(history->entries[i]);
    }
    
    free(history->entries);

    history->currentCapacity = 0;
    history->itemCount = 0;
    history->entries = NULL;
}