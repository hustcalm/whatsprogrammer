#include <cstdio>

struct A
{
    A() { puts("A()"); }
    ~A() { puts("~A()"); }
};

struct B
{
    B() { puts("B()"); }
    ~B() { puts("~B()"); }
};

struct C
{
    A a;
    B b;
};

struct A_id
{
    A_id() : id(count++)
    {
        printf("A(%d)\n", id);
    }

    ~A_id()
    {
        printf("~A(%d)\n", id);
    }

    int id;
    static int count;
};

int main()
{
    C c;
    
    A_id array0[4];

    A* array = new A[4];
    delete[] array;

    A* array1 = new A[4];
    delete array1;
}
