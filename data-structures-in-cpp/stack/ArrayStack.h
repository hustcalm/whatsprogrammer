#ifndef ARRAY_STACK_HXX
#define ARRAY_STACK_HXX

#include <iostream>
#include "ArrayStack.h"
using namespace std;

template<class T> 
class ArrayStack{
    public:
        ArrayStack();
        ArrayStack(int capacity);
        ~ArrayStack();

        void push(T t);
        T peek();
        T pop();
        int size();
        int capacity();
        bool isEmpty();
        bool isFull();
    private:
        T *arr;
        int count;
        int _capacity;
};

// 创建“栈”，默认大小是12
template<class T>
ArrayStack<T>::ArrayStack(): _capacity(12)
{
    arr = new T[12];
    if (!arr) 
    {
        cout<<"arr malloc error!"<<endl;
    }
}

template<class T>
ArrayStack<T>::ArrayStack(int capacity): _capacity(capacity)
{
    arr = new T[_capacity];
    if(!arr) {
        cout << "memory allocation failed!" << endl;
    }
}

// 销毁“栈”
template<class T>
ArrayStack<T>::~ArrayStack() 
{
    if (arr) 
    {
        delete[] arr;
        arr = NULL;
    }
}

// 将val添加到栈中
template<class T>
void ArrayStack<T>::push(T t) 
{
    //arr[count++] = val;
    if(isFull()) {
        // stack has no more capacity, need more space
        T* new_arr = new T[_capacity*2];
        for(int i =0; i < _capacity; ++i) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        _capacity *= 2;
    }

    arr[count++] = t;
}

// 返回“栈顶元素值”
template<class T>
T ArrayStack<T>::peek() 
{
    if(!isEmpty()) {
        return arr[count-1];
    }
    else {
        // throw exception
    }
}

// 返回“栈顶元素值”，并删除“栈顶元素”
template<class T>
T ArrayStack<T>::pop() 
{
    if(isEmpty()) {
        // throw exception
    }

    int ret = arr[count-1];
    count--;
    return ret;
}

// 返回“栈”的大小
template<class T>
int ArrayStack<T>::size() 
{
    return count;
}

// 返回“栈”的容量
template<class T>
int ArrayStack<T>::capacity() 
{
    return _capacity;
}

// 返回“栈”是否为空
template<class T>
bool ArrayStack<T>::isEmpty()
{
    return size()==0;
}

// 返回“栈”是否为满
template<class T>
bool ArrayStack<T>::isFull()
{
    return size()==_capacity;
}

#endif
