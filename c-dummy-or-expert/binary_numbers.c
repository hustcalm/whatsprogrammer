#include <stdio.h>

int main()
{
    long i = 65536 << 16;
    printf("%d\n", i);

    i = 65535 << 16;
    printf("%d\n", i);

    i = -2147483648;
    printf("%d\n", i);

    --i;
    printf("%d\n", i);

    return 0;
}
