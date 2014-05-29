#include <stdio.h>

void fun()
{
    static int a = 3;
    if(--a) fun();
    printf("%d\n", a);
}

int main()
{
    fun();
    printf("next\n");
    fun();
}
