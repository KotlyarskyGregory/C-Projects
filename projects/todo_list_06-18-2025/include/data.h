#ifndef DATA_H
#define DATA_H

#include <time.h>

typedef struct Data 
{
    char *taskName;
    char *category;
    char *taskDescription;
    char *priority;
    time_t inputDate;
    time_t dueDate;

} Data;

// struct tm
// {
//     int tm_sec;   // seconds [0, 60]
//     int tm_min;   // minutes [0, 59]
//     int tm_hour;  // hours   [0, 23]
//     int tm_mday;  // day of month [1, 31]
//     int tm_mon;   // months since January [0, 11]
//     int tm_year;  // years since 1900
//     int tm_wday;  // day of week (0 = Sunday) [ignored by mktime]
//     int tm_yday;  // day of year [ignored]
//     int tm_isdst; // daylight saving time flag

// };

Data* initData();

// void freeData();

#endif