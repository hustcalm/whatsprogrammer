#include <iostream>
using namespace std;

class Base {
    int x;
    public:
        Base(int b) : x(b) {}
        virtual void display() {
            cout << x << endl;
        }
};

class Derived: public Base {
    int y;
    public:
        Derived(int d): Base(d), y(d) {}
        void display() {
            cout << y << endl;
        }
};

int main()
{
    Base b(2);
    Derived d(3);
    b.display();
    d.display();
    Base* p = &d;
    p->display();
    return 0;
}
