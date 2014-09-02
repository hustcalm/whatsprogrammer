// heapsort.hpp
class HeapSort:public BaseSort {
public:
    HeapSort(int Array[], int len) : BaseSort() { 
        this->Array = Array;
        this->len = len;
    }
    void sort();

private:
    /* 建堆 */
    void buildMaxHeap();
 
    /* 调整堆，以保持最大堆性质 */
    void maxHeapIfy( int i , int curlen);
 
    /* 堆排序 */
    void heapSort();
 
    /* 返回父节点下标 */
    int Parent(int i) { 
        if ( i % 2 == 0 ) 
            return i/2;
        else
            return i/2 + 1;
    };
 
    /* 返回左孩子节点下标 */
    int Left(int i) { return 2 * i + 1; };
 
    /* 返回右孩子节点下标 */
    int Right(int i) { return 2 * i + 2; };

private:
    int* Array;
    int len;
};
