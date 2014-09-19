#include <stdio.h>

int main()
{
    char num;

    for (num = 0; num < 255; ) {
        num += num;
    }
    printf("The num is %d\n", num);

    return 0;
}
