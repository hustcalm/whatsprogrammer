#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 11

struct Matrix
{
    int a[N][N];
}res, tmp, origin, magic;

int n,m;
int expn;
struct Matrix mul(struct Matrix x, struct Matrix y)
{
    int i,j,k;
    memset(tmp.a,0,sizeof(tmp.a));
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            for(k=1;k<=n;k++)
            {
                tmp.a[i][j]+=(x.a[i][k]*y.a[k][j])%m;
                tmp.a[i][j]%=m;
            }
    return tmp;
}

void quickpow(int k)
{
    int i;
    memset(res.a,0,sizeof(res.a));
    for(i=1;i<=n;i++)
        res.a[i][i]=1;
    while(k)
    {
        if(k&1)
            res=mul(res,origin);
        origin=mul(origin,origin);
        k>>=1;
    }
}

int main1()
{
    int t,i,j,k;
    m=9973;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf("%d",&origin.a[i][j]);
        quickpow(k);

        int sum=0;
        for(i=1;i<=n;i++)  //求主对角线上各项的和
            sum+=res.a[i][i];
        printf("%d\n",sum%m);

    }
    return 0;
}

int main()
{
    m = 13;
    n = 5;
    expn = 12;

    srand((unsigned)time(NULL));
    //expn = rand()%100;

    int r =5, c = 5;
    for(int i = 1; i <= r; ++i) {
        for(int j = 1; j <= c; ++j) {
            int temp = rand()%100;
            origin.a[i][j] = temp;
            magic.a[i][j] = temp;
        } 
    }

    quickpow(expn);

    printf("A^%d mod 13:\n", expn);
    for(int i = 1; i <= r; ++i)
    {
        for(int j = 1; j <= c; ++j) {
            printf("%d ", res.a[i][j]);
        }
        printf("\n");
    }

    printf("A mod 13:\n");
    for(int i = 1; i <= r; ++i)
    {
        for(int j = 1; j <= c; ++j) {
            printf("%d ", magic.a[i][j] % m);
        }
        printf("\n");
    }
    
}
