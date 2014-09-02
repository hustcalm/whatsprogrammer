#include "baseSort.h"
#include "quickSort.h"

#define DEBUG 1

void QuickSort::sort() {
    quicksort(Array, 0, len-1);
}

void QuickSort::quicksort(int Array[], int start, int end) {
    if ( start < end ) {
        int mid = this->partition(Array, start, end);
        if ( start < mid - 1 )
            quicksort(Array, start, mid-1 );
        if ( mid + 1 < end )
            quicksort(Array, mid+1, end);
    }
}
int QuickSort::partition(int Array[], int start, int end) {
    int i, j, x, tmp;
    x = Array[end];
    i = start -1;
    
    for ( j = start; j < end; j++ ) {
        if ( Array[j] <= x) {
            i++;
            tmp = Array[j];
            Array[j] = Array[i];
            Array[i] = tmp;
        }
    }
    
    tmp = Array[end];
    Array[end] = Array[i+1];
    Array[i+1] = tmp;
    if (DEBUG) {
        printArray(Array, len, "MidResult");
    }
    return i+1;
}

int main()
{
    int a[10] = {7,3,2,9,8,5,1,10,4,6};
    int len = 10;
     
    QuickSort* quicksort= new QuickSort(a, len);
    quicksort->sort();
    printArray(a, len, "QuickSort");
}

