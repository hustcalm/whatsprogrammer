#include <iostream>
using namespace std;

class A {
    public:
        int a;
        char b;
        virtual void print() {
            cout<<"this is father's function"<<endl;
        }
};

class B:A {
    public:
        virtual void print() {
            cout<<"this is child's function"<<endl;
        }
};

int main()
{
    cout<<sizeof(A) << " " <<sizeof(B)<<endl;
    return 0;
}
