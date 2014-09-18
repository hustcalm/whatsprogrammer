#include <cstdio>

class A {
    public:
        A() {}
        A(int size) {
            _size = size;
            int *a = new int[_size];
            for(int i = 0; i < _size; ++i)
                a[i] = i;
        }

        int get(int idx) {
            return idx > _size ? -1:a[idx];
        }

    private:
        int _size;
        int *a;
};

int main()
{
    A a(10);
    fprintf(stderr, "a.get(0) = %d\n", a.get(0));
    fprintf(stderr, "a.get(5) = %d\n", a.get(5));
    fprintf(stderr, "a.get(10) = %d\n", a.get(10));
    return 0;
}
