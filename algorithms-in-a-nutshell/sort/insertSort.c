void insertSort1(int a[], int n)
{
    int i,j,k;

    for(i = 1; i < n; i++)
    {
        for(j = i-1; j >= 0; j--)
        {
            if(a[j] < a[i])
                break;
        }

        // Move the elements
        if(j != i-1)
        {
            int temp = a[i];
            for(k = i-1; k > j; k--)
                a[k+1] = a[k];

            a[k+1] = temp;
        }
    }
}

void insertSort2(int a[], int n)
{
    int i,j;

    for(i = 1; i < n; i++)
    {
        if(a[i] < a[i-1])
        {
            int temp = a[i];

            // Move while searching
            for(j = i-1; j >= 0 && a[j] > a[i]; j--)
                a[j+1] = a[j];

            a[j+1] = temp;
        }
    }
}

void insertSort3(int a[], int n)
{
    int i,j;

    for(i = 1; i < n; i++)
    {
        if(a[i] < a[i-1])
        {
            // compare with bubble sort here
            // bubble sort will pick one bubble for one loop, thus making a sorted list
            // insert sort will maintain a sorted list after adding one element for each loop
            for(j = i - 1; j >= 0 && a[j] > a[j+1]; j--)
                swap(a[j], a[j+1]);
        }
    }
}
