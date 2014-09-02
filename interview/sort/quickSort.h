class QuickSort : public BaseSort {
public:
    QuickSort(int Array[], int len) : BaseSort() {
        this->Array = Array;
        this->len = len;
    }
    void sort();
private:
    int partition(int Array[], int start, int end);
    void quicksort(int Array[], int start, int end);
private:
    int* Array;
    int len;
};
