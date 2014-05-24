int adjustArray(int s[], int l, int r)
{
    int i = l, j = r;
    int pivot = s[l]; // or choose the middle one, swap(s[l], s[middle]), or pick randomly

    while(i < j)
    {
        while(i < j && s[j] >= pivot)
            j--;

        if(i < j)
        {
            s[i] = s[j];
            i++;
        }

        while(i < j && s[i] < pivot)
            i++;

        if(i < j)
        {
            s[j] = s[i];
            j--;
        }
    }

    // i == j now, place the pivot to the right place
    s[i] = pivot;

    return i;
}

void quickSort(int s[], int l, int r)
{
    if(l < r)
    {
        int i = adjustArray(s, l, r);
        quickSort(s, l, i-1);
        quickSort(s, i+1, r);
    }
}
