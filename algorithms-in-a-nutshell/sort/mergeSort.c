void mergeTwoArrays(int a[], int n, int b[], int m, int c[])
{
    int i,j,k;

    i = j = 0;

    while(i < n && j < m)
    {
        if(a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    while(i < n)
        c[k++] = a[i++];

    while(j < m)
        c[k++] = a[j++];
}

void mergeArray(int a[], int first, int mid, int last, int temp[])
{
    int i = fisrt, j = mid + 1;
    int m = mid, n = last;
    int k = 0;

    while(i <= mid && j <= last)
    {
        if(a[i] < b[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while(i <= mid)
        temp[k++] = a[i++];

    while(j <= last)
        temp[k++] = a[j++];

    for(i = 0; i < k; i++)
        a[first + i]  = temp[i];
}

void mergeSort(int a[], int first, int last, int temp[])
{
    if(first < last)
    {
        int mid = (first + last)/2;
        mergeSort(a, first, mid, temp);
        mergeSort(a, mid+1, last, tmep);
        mergeArray(a, first, mid, last, temp);
    }
}

bool MergeSort(int a[], int n)
{
    int *p = new int[n];

    if(p == NULL)
        return false;

    mergeSort(a, 0, n-1, p);

    delete[] p;

    return true;
}
