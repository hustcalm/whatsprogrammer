#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int gCount = 0;

void mergeArray(int a[], int first, int mid, int last, int temp[])
{
    int i = first, j = mid + 1;
    int m = mid, n = last;
    int k = 0;

    while(i <= m && j <= n)
    {
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
        {
            temp[k++] = a[j++];
            gCount += m - i + 1;
        }
    }

    while(i <= m)
        temp[k++] = a[i++];

    while(j <= n)
        temp[k++] = a[j++];

    for(i = 0; i < k; i++)
        a[first + i] = temp[i];
}

void mergeSort(int a[], int first, int last, int temp[])
{
    if(first < last)
    {
        int mid = (first + last)/2;
        mergeSort(a, first, mid, temp);
        mergeSort(a, mid+1, last, temp);
        mergeArray(a, first ,mid, last, temp);
    }
}

bool MergeSort(int a[], int n)
{
    int *p = (int*)malloc(n*sizeof(int));
    if (p == NULL)
        return false;

    mergeSort(a, 0, n-1, p);

    free(p);

    return true;
}

int main()
{
    const int NUM = 10;
    int a[NUM] = {1, 5, 9, 4, 6, 3, 10, 18, 19, 2};

    gCount = 0;
    MergeSort(a, NUM);

    printf("Reverse numbers: %d.\n", gCount);

    return 0;
}
