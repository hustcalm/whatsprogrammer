#include <iostream>
#include <string>
using namespace std;

class A{
    virtual void func1(){}
};

class B:public A{
    virtual void func1(){}
};

int main()
{
    A a;
    A* a1 = new A();
    B* b1 = new B();
    cout<<"int type name: "<<typeid(int).name()<<endl;
    cout<<"char type name: "<<typeid(char).name()<<endl;
    cout<<"string type name: "<<typeid(string).name()<<endl;
    cout<<"A type name: "<<typeid(a).name()<<endl;
    cout<<"A type name: "<<typeid(a1).name()<<endl;
    cout<<"B type name: "<<typeid(b1).name()<<endl;
    //a1 = static_cast<A*>(b1);
    a1 = dynamic_cast<A*>(b1);
    cout<<"A type name: "<<typeid(a1).name()<<endl;
    A* a2 = new B();
    cout<<"A type name: "<<typeid(a2).name()<<endl;
}
