#ifndef HISTORY
#define HISTORY

#define INITIAL_CAPACITY 10;

typedef struct {
    char **entries;
    int itemCount;
    int currentCapacity;

} History;

void initHistory(History *history, int intitialCapacity);

void addToHistory(History *history, const char *entry);

void getHistory(const History *history);

void freeHistory(History *history);

#endif