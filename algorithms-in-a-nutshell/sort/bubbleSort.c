void bubbleSort1(int a[], int n)
{
    int i,j;
    for(i = 0; i < n; i++)
        for(j = 1; j < n-i; j++) 
            if(a[j] < a[j-1])
                swap(a[j], a[j-1]);
}

void bubbleSort2(int a[], int n)
{
    int j,k;
    bool flag;

    k = n;
    flag = true;

    while(flag) {
        flag = false;

        for(j = 1; j < k; j++)
            if(a[j] < a[j-1]) {
                swap(a[j], a[j-1]);
                flag = true;
            }

        k--;
    }
}

void bubbleSort3(int a[], int n)
{
    int j,k;
    int flag;

    flag = n;

    while(flag > 0) {
        k = flag;
        flag = 0;

        for(j = 1; j < k; j++)
            if(a[j] < a[j-1]) {
                swap(a[j], a[j-1]);
                flag = j;
            }
    }
}
