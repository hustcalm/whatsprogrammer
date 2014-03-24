#include <stdio.h>

int main(int argc, char* argv[])
{
    int iter1, iter2;

    for(iter1 = 0; iter1 < 100; iter1++) {
        printf(".");
        sleep(1);
    }

    for(iter2 = 0; iter2 < 100; iter2++) {
        fprintf(stderr, "x");
        sleep(1);
    }

    return 0;
}
