#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

class MyString
{
public:
    MyString(const char *str = NULL);
    MyString(const MyString &other);
    ~MyString(void);
    MyString & operator = (const MyString &other);
    int OutputStr(void);
private:
    char *m_data;
};

MyString::MyString(const char *str) //普通的构造函数
{
    cout << "Normal contructor..." <<endl;

    if (str == NULL)
    {
        m_data = new char[1];
        *m_data = '\0';
    }
    else
    {
        int length = strlen(str);
        m_data = new char[length + 1];
        strcpy(m_data, str);
    }
}

MyString::MyString(const MyString &other) //拷贝构造函数
{
    cout << "Copy contructor..." <<endl;

    int length = strlen(other.m_data);
    m_data = new char[length + 1];
    strcpy(m_data, other.m_data);
}

MyString::~MyString(void)
{
    delete [] m_data;
}

MyString & MyString::operator = (const MyString &other) //赋值操作
{
    cout << "Assignment..." <<endl;

    if (this == &other)
    {
        return *this;
    }

    delete [] m_data;
    int length = strlen(other.m_data);
    m_data = new char[length + 1];
    strcpy(m_data, other.m_data);
    return *this;
}

int MyString::OutputStr(void)
{
    int length = 0;
    length = strlen(m_data);
    printf("the output string is : %s", m_data);
    return length;
}

int main(int argc, char* argv[])
{
    MyString str("hello, world"); //进入普通构造函数
    MyString str2 = str; //初始化,进入拷贝构造函数
    MyString str3(str); //初始化,进入拷贝构造函数
    str2 = str; //赋值,进入赋值操作
    str2.OutputStr();

    //MyString *str = new MyString("hello, world"); //普通构造函数
    //MyString *str2 = new MyString(*str); //拷贝构造函数
    //*str2 = *str; //赋值操作
    //str2->OutputStr();

    getchar();
    return 0;
}
