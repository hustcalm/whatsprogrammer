#include <stdio.h>
#include <string.h>
#include <assert.h>

void BigNumMultiply(const char *str1, const char *str2, char *product)
{
    assert(str1 != NULL && str2 != NULL && product != NULL);

    int i, j;
    int len1 = (int)strlen(str1);
    int len2 = (int)strlen(str2);
    // 两数相乘的最大长度是len1+len2+1，这么思考，如果乘数是999，则如果是乘以10000，最多增加4位
    int *dest = (int*)malloc(sizeof(int)*(len1+len2+1));
    
    // 构造dest数组，用于存放没有考虑carry的结果
    for (i=0; i<len1+len2+1; i++) { dest[i] = 0; }

    // 相乘，暂时不考虑进位
    for (i=0; i<len1; i++)
    {
        for (j=0; j<len2; j++)
        {
            dest[i+j+1] += (str1[i]-'0')*(str2[j]-'0');
        }
    }

    // 高位在数组首位，因此从后向前进位
    for (i=len1+len2-1; i>=0; i--)
    {
        // 当i=0时dest[0]=0,这个条件不成立，所以不用担心dest[-1]
        if (dest[i] >= 10)
        {
            dest[i-1] += dest[i]/10;
            dest[i] %= 10;
        }
        product[i] = dest[i]+'0';
    }

    // 去掉结果开头的0
    if (product[0] == '0')
    {
        i = 1;
        while (product[i] != '\0')
        {
            product[i-1] = product[i];
            i++;
        }
        product[i-1] = '\0';
    }

    free(dest);
    return;
}

int main(void)
{
    char product[50] = {0};

    BigNumMultiply("234324", "54651", product);
    printf("234324*54651 = %s\n", product);
    BigNumMultiply("2343240", "546510", product);
    printf("2343240*546510 = %s\n", product);

    getchar();
    return 0;
}
