#include <iostream>
using std::ostream;

#define MAXLEN 10001
#define POSITIVE 1
#define NEGATIVE -1
#define ZERO 0

class HugeInt
{
    friend ostream& operator<<(ostream& output,const HugeInt& n);
    public:

    /*  构造函数    */
        HugeInt(int=0);
        HugeInt(char *str);
        HugeInt(const HugeInt& other);
        HugeInt& operator=(const HugeInt& other);

    /*  关系运算符   */
        bool operator==(const HugeInt &other)const;
        bool operator==(const int &x)const;
        bool operator!=(const HugeInt &other)const;
        bool operator!=(const int &x)const;

        bool operator>(const HugeInt &other)const;
        bool operator>(const int &x)const;
        bool operator>=(const HugeInt &other)const;
        bool operator>=(const int &x)const;

        bool operator<(const HugeInt &other)const;
        bool operator<(const int &x)const;
        bool operator<=(const HugeInt &other)const;
        bool operator<=(const int &x)const;

    /*  加法运算    */
        HugeInt operator+(const HugeInt &other)const;
        HugeInt operator+(const int &x)const;
        HugeInt operator+=(const HugeInt &other);
        HugeInt operator+=(const int &x);
        HugeInt& operator++();//前置
        HugeInt operator++(int);//后置

    /*  减法运算    */
        HugeInt operator-();//负号
        HugeInt operator-(const HugeInt &other)const;
        HugeInt operator-(const int &x)const;
        HugeInt operator-=(const HugeInt &other);
        HugeInt operator-=(const int &x);
        HugeInt& operator--();//前置
        HugeInt operator--(int);//后置

    /*  乘法运算    */
        HugeInt operator*(const HugeInt &other)const;
        HugeInt operator*(const int &x)const;
        HugeInt operator*=(const HugeInt &other);
        HugeInt operator*=(const int &x);

    /*  除法运算    */
        HugeInt operator/(const HugeInt &other)const;
        HugeInt operator/(const int &x)const;
        HugeInt operator/=(const HugeInt &other);
        HugeInt operator/=(const int &x);

    /*  求模运算    */
        HugeInt operator%(const HugeInt &other)const;//to do:debug
        int operator%(const int &x)const;
        HugeInt operator%=(const HugeInt &other);
        int operator%=(const int &x);

    private:
        char num[MAXLEN];
        int length;
        int sign;
        bool isZero()const;
};
