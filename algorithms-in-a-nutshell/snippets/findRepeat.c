int radixSort(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        while(a[i] != i)
        {
            if(a[i] == a[a[i]])
                return a[i];

            swap(a[i], a[a[i]]);
        }
    }

    return -1;
}
