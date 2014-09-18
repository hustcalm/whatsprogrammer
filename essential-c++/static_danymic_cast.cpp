#include <iostream>
using namespace std;

class A {
    public:
        virtual void foo() {
        }
};


class B {
    public:
        virtual void foo() {
        }
};

class C: public A, public B {
    virtual void foo() {
    }
};

void bar1(A *pa) {
    B *pc = dynamic_cast<B *>(pa);
}

void bar2(A *pa) {
    B *pc = static_cast<B *>(pa);
}

void bar3() {
    C c;
    A *pa = &c;
    B *pb = static_cast<B *>(static_cast<C *>(pa));
}
