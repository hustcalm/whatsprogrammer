/**
 * do you know exactly what will sizeof do?
 * use the two instructions below to find out:
 * 1. gcc sizeof.c
 * 2. gcc -pendantic -Wall sizeof.c
 */

#include <stdio.h>

int fun()
{
    return 0;
}

int fun2(const int a, const int b)
{
    return a + b;
}

void fun3()
{
}

double fun4()
{
    return 1.0;
}

int main()
{
    int (*fun2_pointer)(int, int);
    fun2_pointer = fun2;

    printf("sizeof(void): %d\n", sizeof(void));
    printf("sizeof(char): %d\n", sizeof(char));
    printf("sizeof(int): %d\n", sizeof(int));
    printf("sizeof(float): %d\n", sizeof(float));

    printf("sizeof(void*): %d\n", sizeof(void*));
    printf("sizeof(char*): %d\n", sizeof(char*));
    printf("sizeof(int*): %d\n", sizeof(int*));
    printf("sizeof(float*): %d\n", sizeof(float*));

    printf("test function address fun:%p\n",fun);
    printf("test sizeof for fun:%d\n", sizeof(fun));

    printf("test function address fun2:%p\n",fun2);
    printf("test sizeof for fun2:%d\n", sizeof(fun2));

    printf("test function pointer address fun2:%p\n",fun2_pointer);
    printf("test sizeof for fun2 pointer:%d\n", sizeof(fun2_pointer));

    printf("test function address fun3:%p\n",fun3);
    printf("test sizeof for fun3:%d\n", sizeof(fun3));

    printf("test function address fun4:%p\n",fun3);
    printf("test sizeof for fun4:%d\n", sizeof(fun4));

    return 0;
}
