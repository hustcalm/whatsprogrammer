#include <iostream>
#include "ArrayStack.h"
using namespace std;

int main() 
{
    int tmp=0;
    ArrayStack<int> *astack = new ArrayStack<int>();
    ArrayStack<int> *astack2 = new ArrayStack<int>(20);
    cout<<"capacity of astack2: " << astack2->capacity() << endl;;

    for(int i = 0; i < 21; ++i) {
        astack2->push(i);
    }

    cout<<"capacity of astack2: " << astack2->capacity() << endl;;

    cout<<"main"<<endl;

    // 将10, 20, 30 依次推入栈中
    astack->push(10);
    astack->push(20);
    astack->push(30);

    // 将“栈顶元素”赋值给tmp，并删除“栈顶元素”
    tmp = astack->pop();
    cout<<"tmp="<<tmp<<endl;

    // 只将“栈顶”赋值给tmp，不删除该元素.
    tmp = astack->peek();

    astack->push(40);

    while (!astack->isEmpty())
    {
        tmp = astack->pop();
        cout<<tmp<<endl;
    }

    return 0;
}
