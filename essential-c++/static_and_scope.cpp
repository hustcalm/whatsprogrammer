#include <iostream>

using namespace std;

int i = 0;
int fun(int n)
{
    static int a = 2;
    a++;
    return a*n;
}

int main()
{
    int k = 5;
    {
        int i = 2;
        k += fun(i);
    }
    k += fun(i);
    cout<<k<<endl;
    return 0;
}
