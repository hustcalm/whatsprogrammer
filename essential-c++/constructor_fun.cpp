#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MyClass {
    public:
        MyClass() {cout << "Constructor invoked!" << endl;}
};

int main()
{
    cout << sizeof(string) << endl;
    string s;
    cout << sizeof(s) << endl;
    MyClass a[5], *b[6];
    vector<MyClass> f(5);
    return 0;
}
