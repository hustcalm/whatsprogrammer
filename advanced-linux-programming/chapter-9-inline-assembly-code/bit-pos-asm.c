#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    long max = atoi(argv[1]);
    long number;
    unsigned position;
    volatile unsigned result;

    for(number = 1; number <= max; number++) {

        asm("bsrl %1, %0" : "=r" (position) : "r" (number));

        result = position;
    }

    return 0;
}
