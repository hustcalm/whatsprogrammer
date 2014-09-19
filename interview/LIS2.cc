#include <iostream>
using namespace std;
 
/* 最长递增子序列 LIS
 * 设数组长度不超过 30
 * quicksort + LCS
*/
 
void swap(int * arr, int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}
 
void qsort(int * arr, int left, int right)
{
    if(left >= right)    return ;
    int index = left;
    for(int i = left+1; i <= right; ++i)
    {
        if(arr[i] < arr[left])
        {
            swap(arr,++index,i);
        }
    }
    swap(arr,index,left);
    qsort(arr,left,index-1);
    qsort(arr,index+1,right);
}
 
int dp[31][31];
 
int LCS(int * arr, int * arrcopy, int len)
{
    for(int i = 1; i <= len; ++i)
    {
        for(int j = 1; j <= len; ++j)
        {
            if(arr[i-1] == arrcopy[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }else if(dp[i-1][j] > dp[i][j-1])
            {
                dp[i][j] = dp[i-1][j];
            }else
            {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    return dp[len][len];
}
 
int main()
{
    int arr[] = {1,-1,2,-3,4,-5,6,-7};
    int arrcopy [sizeof(arr)/sizeof(int)];
 
    memcpy(arrcopy,arr,sizeof(arr));
    qsort(arrcopy,0,sizeof(arr)/sizeof(int)-1);
 
    /* 计算LCS，即LIS长度 */
    int len = sizeof(arr)/sizeof(int);
    printf("%d\n",LCS(arr,arrcopy,len));
    return 0;
}
