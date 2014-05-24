int selectionSort(int a[], int n)
{
    int i,j;
    int minIndex;

    for(i = 0; i < n; i++)
    {
        minIndex = i;

        for(j = i+1; j < n; j++)
        {
            if(a[j] < a[minIndex])
                minIndex = j;
        }

        swap(a[i], a[minIndex]);
    }
}
