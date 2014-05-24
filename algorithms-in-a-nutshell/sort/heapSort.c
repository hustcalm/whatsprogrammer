/**
 * do heap fix
 * after adding an element
 * i indicates from which node on counting from 0
 */
void minHeapFixup(int a[], int i)
{
    int j, temp;

    temp = a[i];
    j = (i-1)/2; // parent node

    while(j >= 0 && i != 0)
    {
        if(a[j] <= temp)
            break;

        // Move bigger elements down
        // looks like insertion sort
        a[i] = a[j];
        i = j;
        j = (i-1)/2;
    }

    a[i] = temp;
}

/**
 * the shorter one
 */
void minHeapFixup1(int a[], int i)
{
    for(int j = (i-1)/2; (j >= 0 && i != 0) && a[j] < a[i]; i = j, j = (i-1)/2)
        swap(a[i], a[j]);
}

/**
 * add one node to heap
 * n is the index to place the node
 * num is the node itself
 */
void minHeapAddNumber(int a[], int n, int num)
{
    a[n] = num;
    minHeapFixup(a, n);
}

/**
 * fix the heap
 * after deleting the root node
 */
void minHeapFixdown(int a[], int i, int n)
{
    int j, temp;

    temp = a[i];
    j = 2*i + 1;

    while(j < n)
    {
        // find the smallest child
        if(j + 1 < n && a[j+1] < a[j])
            j++;

        // if parent node is smallest, then done
        if(a[j] >= temp)
            break;

        // else, perform insertion sort, let smaller children go up
        a[i] = a[j];
        i = j;
        j = 2*i + 1;
    }

    a[i] = temp;
}

/**
 * delete the root node
 * make the last node the root node
 * then fix the heap
 * n is the total number of elements
 */
void minHeapDeleteNumber(int a[], int n)
{
    swap(a[0], a[n-1]);
    minHeapFixdown(a, 0, n-1);
}

/**
 * build the min heap from an array
 */
void makeMinHeap(int a[], int n)
{
    for(int i = n/2 - 1; i>=0; i--)
    {
        minHeapFixdown(a, i, n);
    }
}

/**
 * min heap sort
 * popping the root node iterately
 * i is the node index in an array
 */
void minHeapSort(int a[], int n)
{
    for(int i = n - 1; i >= 1; i--)
    {
        swap(a[i], a[0]);
        minHeapFixdown(a, 0, i);
    }
}
