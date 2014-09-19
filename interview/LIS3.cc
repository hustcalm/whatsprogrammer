#include <iostream>
using namespace std;
 
/* 最长递增子序列 LIS
 * 设数组长度不超过 30
 * DP + BinarySearch
*/
int MaxV[30]; /* 存储长度i+1（len）的子序列最大元素的最小值 */
int len;      /* 存储子序列的最大长度 即MaxV当前的下标*/
/* 返回MaxV[i]中不小于x 的那个元素的下标  */
int BinSearch(int * MaxV, int size, int x)
{
    int left = 0, right = size-1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(MaxV[mid] < x)
        {
            left = mid + 1;
        }else
        {
            right = mid - 1;
        }
    }
    return left;
}
int LIS(int * arr, int size)
{
    MaxV[0] = arr[0]; /* 初始化 */
    len = 1;
    for(int i = 1; i < size; ++i) /* 寻找arr[i]属于哪个长度LIS的最大元素 */
    {
        if(arr[i] > MaxV[len-1]) /* 大于最大的自然无需查找，否则二分查其位置 */
        {
            MaxV[len++] = arr[i];
        }else
        {
            int pos = BinSearch(MaxV,len,arr[i]);
            MaxV[pos] = arr[i];
        }
    }
    return len;
}
int main()
{
    int arr[] = {1,-1,2,-3,4,-5,6,-7};
 
    /* 计算LIS长度 */
    printf("%d\n",LIS(arr,sizeof(arr)/sizeof(int)));
    return 0;
}
