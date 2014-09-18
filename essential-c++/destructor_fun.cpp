#include<iostream> 
using namespace std; 
class Base
{
public: ~Base()
{ cout<<"BASE"; };
}; 

class DERIVED:public Base {
public:
~DERIVED()
{
cout<<"DERIVED";
};
};

int main()
{
    DERIVED x; 
    return 0; 
}
