#include <iostream>
using namespace std;
 
/* LCS
 * 设序列长度都不超过20
*/
 
int dp[21][21]; /* 存储LCS长度, 下标i,j表示序列X,Y长度 */
char X[21];
char Y[21];
int i, j;
 
int main()
{
    cin.getline(X,20);
    cin.getline(Y,20);
 
    int xlen = strlen(X);
    int ylen = strlen(Y);
 
    /* dp[0-xlen][0] & dp[0][0-ylen] 都已初始化0 */
    for(i = 1; i <= xlen; ++i)
    {
        for(j = 1; j <= ylen; ++j)
        {
            if(X[i-1] == Y[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }else if(dp[i][j-1] > dp[i-1][j])
            {
                dp[i][j] = dp[i][j-1];
            }else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    printf("len of LCS is: %d\n", dp[xlen][ylen]);
 
    /* 输出LCS 本来是逆序打印的，可以写一递归函数完成正序打印
       这里采用的方法是将Y作为临时存储LCS的数组，最后输出Y
    */

   
    i = xlen;
    j = ylen;
    int k = dp[i][j];
    char lcs[21] = {'\0'};
    while(i && j)
    {
        if(X[i-1] == Y[j-1] && dp[i][j] == dp[i-1][j-1] + 1)
        {
            lcs[--k] = X[i-1];
            --i; --j;
        }else if(X[i-1] != Y[j-1] && dp[i-1][j] > dp[i][j-1])
        {
            --i;
        }else
        {
            --j;
        }
    }
    printf("%s\n",lcs);
    return 0;
}
