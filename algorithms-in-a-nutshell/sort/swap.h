inline void swap1(int& a, int& b)
{
    if(a != b)
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }
}

inline void swap2(int& a, int& b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}
