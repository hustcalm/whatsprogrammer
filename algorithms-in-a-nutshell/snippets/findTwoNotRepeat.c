/**
 * use xor to find one unique number easily
 * for two unique numbers, divide the numbers into two groups
 * then use the easier normal xor method
 */

void findTwoNotRepeatNumbers(int a[], int n, int* num1, int* num2)
{
    int i,j;
    int temp;

    // temp == num1 xor num2
    for(i = 0; i < n; i++)
    {
        temp ^= a[i];
    }

    // find the first different bit
    for(j = 0; j < sizeof(int)*8; j++)
        if((temp >> j) & 1 == 1)
            break;

    // the index is j
    // use the normal xor method
    *num1 = 0;
    *num2 = 0;
    for(i = 0; i < n; i++)
    {
        if((a[i] >> j) & 1 == 1)
            *num1 ^= a[i];
        else
            *num2 ^= a[i];
    }
}
