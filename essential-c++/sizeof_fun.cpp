#include <iostream>
#include <string>

using namespace std;

struct xx {
    long long _x1; 
    char _x2; 
    int _x3; 
    char _x4[2]; 
    static int _x5;
}; 
int xx::_x5;

int main()
{
    cout << sizeof(string) << endl;
    string s;
    cout << sizeof(s) << endl;
    cout << sizeof(xx) << endl;
    xx xxx;
    cout << sizeof(xxx) << endl;
}
