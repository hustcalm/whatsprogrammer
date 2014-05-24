void shellSort1(int a[], int n)
{
    int i,j,gap;

    for(gap = n/2; gap > 0; gap /= 2)
    {
        // Insert sort for each group of elements
        // till gap = 1
        for(i = 0; i < gap; i++)
        {
            for(j = i+gap; j < n; j += gap)
            {
                if(a[j] < a[j-gap])
                {
                    int temp = a[j];
                    int k = j - gap;

                    while(k>=0 && a[k] > temp)
                    {
                        a[k+gap] = a[k];
                        k -= gap;
                    }

                    a[k+gap] = temp;
                }
            }
        }
    }
}


void shellSort2(int a[], int n)
{
    int j,gap;

        for(gap = n/2; gap > 0; gap /= 2)
        {
            // start from the 'gap' element
            // and compare with the elements in its group
            for(j = gap; j < n; j++)
            {
                if(a[j] < a[j-gap])
                {
                    int temp = a[j];
                    int k = j - gap;

                    while(k>=0 && a[k] > temp)
                    {
                        a[k+gap] = a[k];
                        k -= gap;
                    }

                    a[k+gap] = temp;
                }
            }
        }
}

void shellSort3(int a[], int n)
{
    int i,j,gap;

    for(gap = n/2; gap > 0; gap /=2)
    {
        for(i = gap; i < n; i++)
        {
            while(j = i - gap; j >=0 && a[j] > a[j+gap]; j -= gap)
                swap(a[j], a[j+gap]);
        }
    }
}
