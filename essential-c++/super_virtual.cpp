#include <iostream>
using namespace std;

class Base {
     public:
            virtual void f() { cout << "Base::f" << endl; }
            virtual void g() { cout << "Base::g" << endl; }
            virtual void h() { cout << "Base::h" << endl; }
 
};

typedef void(*Fun)(void);

int main()
{
    Base b;
 
    Fun pFun = NULL;

    cout << "虚函数表地址：" << (int*)(&b) << endl;
    cout << "虚函数表 — 第一个函数地址：" << (int*)*(int*)(&b) << endl;
    cout << "虚函数表 — 第二个函数地址：" << ((int*)*(int*)(&b) + 1) << endl;
    cout << "虚函数表 — 第三个函数地址：" << ((int*)*(int*)(&b) + 2) << endl;

    // Invoke the first virtual function 
    pFun = (Fun)*((int*)*(int*)(&b));
    pFun();

    return 0;
}

