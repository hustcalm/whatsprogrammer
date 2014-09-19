#include <stdio.h>

int main()
{
    for(char num = 0; num < 127; ++num)
    {
        printf("%c ", num);
        if(num  % 10)
            printf("\n");
    }

    return 0;
}
