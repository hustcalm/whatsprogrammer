#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    long max = atoi(argv[1]);
    long number;
    long i;
    unsigned position;
    volatile unsigned result;

    for(number = 1; number <= max; number++) {

        for(i = (number >> 1), position = 0; i != 0; position++)
            i >>= 1;

        result = position;
    }

    return 0;
}
