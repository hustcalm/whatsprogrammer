#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Check prime number the naive way
 */
bool isPrimeNormal(int nr)
{
    for(int i = 2; i*i < nr + 1; i++)
    {
        if(nr % i == 0)
            return false;
    }
    
    return true;
}

/**
 * Check prime number using filter
 */
bool marked[10000] = {true};

void generatePrimeTable(nr)
{
    for(int i = 2; i <= nr; i++)
    {
        if((i == 2) || (i % 2 != 0)){
            marked[i] = true;
        }
        else {
            marked[i] = false;
        }
    }

    for(int j = 2; j*j < nr; j++)
    {
        if(marked[j]) {
            for (int k = j*2; k < nr; k += j) {
                marked[k] = false;
            }
        }
    }
}

int main()
{
    printf("Checking prime numbers...\n");

    printf("The naive way for nr = 10000:\n");
    for(int nr = 2; nr <= 10000; nr++){
        if(isPrimeNormal(nr)){
            printf("%d ", nr);
        }
    }
    printf("\n");

    printf("The filter way for nr = 10000:\n");
    int nr = 10000;
    generatePrimeTable(nr);
    for(int i = 2; i<= nr; i++) {
        if(marked[i])
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}

