#include "HugeInt.h"
#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

bool HugeInt::isZero()const
{
    return (sign == ZERO);
}

ostream& operator<<(ostream& output,const HugeInt &n)
{
    if(n.sign == NEGATIVE)
        output << "-";
    int i;
    for(i=n.length-1;i>=0;--i)
        output << n.num[i]+0;
    return output;
}

HugeInt::HugeInt(int x)
{
    memset(num,0,sizeof(num));
    if(x == 0)
    {
        sign=ZERO;
        length=1;
    }
    else
    {
        if(x > 0)
            sign=POSITIVE;
        else
        {
            sign=NEGATIVE;
            x = -x;
        }
        int i=0;
        while(x != 0)
        {
            num[i++] = x%10;
            x /= 10;
        }
        length = i;
    }
}

HugeInt::HugeInt(const HugeInt& other)
{
    *this=other;
}

HugeInt::HugeInt(char *str)
{
    memset(num,0,sizeof(num));
    if(str[0]=='-')
        sign=NEGATIVE;
    else
        sign=POSITIVE;

    int i,j,k,n=strlen(str);
    for(i=0;i<n;i++)
        if(str[i]>'0' && str[i]<='9')break;

    if(i==n)
    {
        sign=ZERO;
        length=1;
        num[0]=0;
    }
    else
    {
        for(k=n-1,j=0;k>=i;--k,++j)
            num[j]=str[k]-'0';
        length=j;
    }
}

HugeInt& HugeInt::operator=(const HugeInt& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    int i;
    sign=rhs.sign;
    length=rhs.length;
    for(i=0;i<MAXLEN;i++)
        num[i]=rhs.num[i];
    return *this;
}

bool HugeInt::operator==(const HugeInt &other)const
{
    if(this->sign != other.sign)return false;
    if(this->length != other.length)return false;
    int i;
    for(i=0;i<length;++i)
        if(this->num[i] != other.num[i])
            return false;
    return true;
}

bool HugeInt::operator==(const int &x)const
{
    return ( (*this) == HugeInt(x) );
}

bool HugeInt::operator!=(const HugeInt &other)const
{
    return !( (*this) == other );
}

bool HugeInt::operator!=(const int &x)const
{
    return !( (*this) == x );
}

bool HugeInt::operator>(const HugeInt &other)const
{
    if(this->sign == other.sign)
    {
        bool flag=(sign == POSITIVE);
        if(this->length != other.length)
            return flag&(this->length > other.length);
        else
        {
            int i;
            for(i=length-1;i>=0;--i)
                if(this->num[i] > other.num[i])
                    return (flag?true:false);
                else if(this->num[i] < other.num[i])
                    return (flag?false:true);
            return false;
        }
    }
    else
        return (this->sign > other.sign);
}

bool HugeInt::operator>(const int &x)const
{
    return ( (*this) > x );
}

bool HugeInt::operator>=(const HugeInt &other)const
{
    return (((*this) > other)||((*this)==other));
}

bool HugeInt::operator>=(const int &x)const
{
    return ( (*this) >= HugeInt(x) );
}

bool HugeInt::operator<(const HugeInt &other)const
{
    return !( (*this) >= other );
}

bool HugeInt::operator<(const int &x)const
{
    return ((*this) < HugeInt(x));
}

bool HugeInt::operator<=(const HugeInt &other)const
{
    return !( (*this) > other );
}

bool HugeInt::operator<=(const int &x)const
{
    return ( (*this) < HugeInt(x) );
}

HugeInt HugeInt::operator+(const HugeInt &other)const
{
    if(this->isZero())
        return other;
    if(other.isZero())
        return *this;

    HugeInt temp(0);
    if(this->sign == other.sign)
    {
        int maxlength=max(length,other.length);
        int i;
        for(i=0;i<maxlength;++i)
        {
            temp.num[i] += (num[i]+other.num[i]);
            temp.num[i+1] += temp.num[i]/10;
            temp.num[i] = temp.num[i]%10;
        }
        temp.sign=sign;
        temp.length=maxlength;
        if(temp.num[temp.length])
            temp.length++;
        return temp;
    }
    else if(this->sign == NEGATIVE)
    {
        temp=(*this);
        temp.sign=POSITIVE;
        return (other-temp);
    }
    else
    {
        temp=other;
        temp.sign=POSITIVE;
        return ((*this)-temp);
    }
}

HugeInt HugeInt::operator+(const int &x)const
{
    return ((*this) + HugeInt(x));
}

HugeInt HugeInt::operator+=(const HugeInt &other)
{
    (*this) = (*this) + other;
    return *this;
}

HugeInt HugeInt::operator+=(const int &x)
{
    (*this) = (*this) + HugeInt(x);
    return *this;
}

HugeInt& HugeInt::operator++()
{
    (*this) = (*this) + HugeInt(1);
    return *this;
}

HugeInt HugeInt::operator++(int)
{
    HugeInt temp(*this);
    (*this) = (*this) + HugeInt(1);
    return temp;
}

HugeInt HugeInt::operator-()
{
    sign = (sign==POSITIVE ? NEGATIVE : fabs(sign));
    return *this;
}

HugeInt HugeInt::operator-(const HugeInt &other)const
{
    if((*this) < other)
        return -(other - (*this));
    else if((*this) == other)
        return HugeInt(0);
    else
    {
        HugeInt temp(*this);
        int i;
        for(i=0;i<temp.length;++i)
            if(temp.num[i] < other.num[i])
            {
                --temp.num[i+1];
                temp.num[i] = temp.num[i]+10-other.num[i];
            }
            else
                temp.num[i] -= other.num[i];
        for(i=temp.length;i>=0;--i)
            if(temp.num[i])
            {
                temp.length = i+1;
                break;
            }
        return temp;
    }
}

HugeInt HugeInt::operator-(const int &x)const
{
    return ((*this) - HugeInt(x));
}

HugeInt HugeInt::operator-=(const HugeInt &other)
{
    (*this) = (*this) - other;
    return *this;
}

HugeInt HugeInt::operator-=(const int &x)
{
    (*this) = (*this) - HugeInt(x);
    return *this;
}

HugeInt& HugeInt::operator--()
{
    (*this) = (*this) - HugeInt(1);
    return *this;
}

HugeInt HugeInt::operator--(int)
{
    HugeInt temp(*this);
    (*this) = (*this) - HugeInt(1);
    return temp;
}

HugeInt HugeInt::operator*(const HugeInt &other)const
{
    if(this->isZero() || other.isZero())
        return HugeInt(0);
    else
    {
        int i,j;
        HugeInt temp(0);
        for(i=0;i < this->length;++i)
            for(j=0;j < other.length;++j)
            {
                temp.num[i+j] += (num[i]*other.num[j]);
                temp.num[i+j+1] += temp.num[i+j]/10;
                temp.num[i+j] %= 10;
            }
        temp.length=(i-1)+(j-1)+1;
        if(temp.num[temp.length])
            ++temp.length;
        temp.sign = this->sign * other.sign;
        return temp;
    }
}

HugeInt HugeInt::operator*(const int &x)const
{
    return (*this)*HugeInt(x);
}

HugeInt HugeInt::operator*=(const HugeInt &other)
{
    (*this) = (*this) * other;
    return *this;
}

HugeInt HugeInt::operator*=(const int &x)
{
    return (*this)*HugeInt(x);
}

int subtract(char *p1,char *p2,int len1,int len2)
{
    int i;
    if(len1 < len2)return -1;
    else if(len1 == len2)
    {
        for(i=len1-1;i>=0;--i)
            if(p1[i] < p2[i])       return -1;
            else if(p1[i] > p2[i])  break;
        if(i < 0)return 0;
    }
    for(i=0;i<len1;++i)
        if(p1[i] < p2[i])
        {
            p1[i+1]--;
            p1[i] = p1[i]+10-p2[i];
        }
        else
            p1[i] -= p2[i];
    for(i=len1-1;i>=0;--i)
        if(p1[i])   return i+1;
    return 0;
}

HugeInt HugeInt::operator/(const HugeInt &other)const
{
    if(this->length < other.length)return HugeInt(0);

    int i,t,z;
    HugeInt result(0),n1(*this),n2(other);

    result.sign = n1.sign * n2.sign;
    t=n1.length - n2.length;
    if(t > 0)
        for(i=length;i>=0;--i)
            if(i-t >= 0)n2.num[i] = n2.num[i-t];
            else        n2.num[i] = 0;
    n2.length = n1.length;
    for(i=0;i<=t;++i)
        while((z=subtract(n1.num,(n2.num)+i,n1.length,n2.length-i))>=0)
        {
            n1.length = z;
            result.num[t-i]++;
        }
    for(i=MAXLEN-1;i>=0;--i)
        if(result.num[i])break;
    if(i>=0)result.length = i+1;
    else    return HugeInt(0);
    return result;
}

HugeInt HugeInt::operator/(const int &x)const
{
    return (*this)/HugeInt(x);
}

HugeInt HugeInt::operator/=(const HugeInt &other)
{
    (*this) = (*this) / other;
    return *this;
}

HugeInt HugeInt::operator/=(const int &x)
{
    return (*this)/HugeInt(x);
}

HugeInt HugeInt::operator%(const HugeInt &other)const
{
    if(this->length < other.length)return *this;

    int i,t,z;
    HugeInt n1(*this),n2(other);

    t=n1.length - n2.length;
    if(t > 0)
        for(i=length;i>=0;--i)
            if(i-t >= 0)n2.num[i] = n2.num[i-t];
            else        n2.num[i] = 0;
    n2.length = n1.length;
    for(i=0;i<=t;++i)
        while((z=subtract(n1.num,(n2.num)+i,n1.length,n2.length-i))>=0)
        {
            if(z == 0)return HugeInt(0);
            n1.length = z;
        }
    return n1;
}

HugeInt HugeInt::operator%=(const HugeInt &other)
{
    (*this) = (*this) % other;
    return *this;
}

int HugeInt::operator%(const int &x)const
{
    int i,exp10[this->length+1],k=0;
    exp10[0]=1%x;
    exp10[1]=10%x;
    for(i=2;i<=this->length;++i)
        exp10[i] = exp10[i-1]*exp10[1]%x;
    for(i=0;i<this->length;++i)
        k = (k+(this->num[i])%x*exp10[i])%x;
    return k;
}

int HugeInt::operator%=(const int &x)
{
    int tmp = (*this)%x;
    (*this) = HugeInt(tmp);
    return tmp;
}

