#include <cstdio>

#ifndef BASE_SORT_H
#define BASE_SORT_H

class BaseSort {
public:
    BaseSort() { }
    virtual void sort() = 0;
};

void printArray(int* array, int len, const char* str)
{
    printf("%s: ", str);
    for(int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

#endif
