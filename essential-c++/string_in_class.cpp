#include <cstdio>
#include <string>
using namespace std;

class A {
    public:
        string a;
        void f1() {printf("Hello World!\n");}
        void f2() {a = "Hello World!\n"; printf("%s\n", a.c_str());}
        virtual void f3() {printf("Hello World!\n");}
        virtual void f4() {a = "Hello World!\n"; printf("%s\n", a.c_str());}
};

int main() {
    A* aptr = NULL; 
    //aptr->f1();
    //aptr->f2();
    //aptr->f3();
    aptr->f4();

    return 0;
}
