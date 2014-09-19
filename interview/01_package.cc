#include <iostream>
using namespace std;
 
char state[11][101]; /* 设 N <= 10 M <= 100 记录路径 */
int dp[101];         /* 使用一维数组01背包 */
int value[11];       /* 本题可将费用与价值看做同一值 */
int i, j;
 
int main()
{
    int N, M;
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        scanf("%d",&value[i]);
    }
 
    while(scanf("%d", &M) != EOF)
    {
        memset(dp,0,sizeof(dp));
 
        /* 01背包 */
        for(i = 0; i < N; ++i)
        {
            for(j = M; j >= value[i]; --j)
            {
                int tmp = dp[j-value[i]] + value[i];
                if(tmp > dp[j])
                {
                    dp[j] = tmp;
                    state[i][j] = 1;
                }
            }
        }
        printf("最接近值：%d\n",dp[M]);
 
        /* 输出方案 */
        i = N;
        j = M;
        while(i-- >= 0)
        {
            if(state[i][j] == 1)
            {
                printf("%d ",value[i]);
                j -= value[i];
            }
        }
        printf("\n");
    }
    return 0;
}
