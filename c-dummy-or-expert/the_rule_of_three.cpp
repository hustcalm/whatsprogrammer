class wibble_ptr {
    public:
        wibble_ptr()
            : ptr(new wibble), count(new int(1)) {
            }

        wibble_ptr(const wibble_ptr & other)
            : ptr(other.ptr), count(other.count) {
                (*count)++;
            }

        wibble_ptr & operator=(const wibble_ptr & rhs) {
            wibble_ptr copy(rhs);
            swap(copy);
            return *this;
        }

        ~wibble_ptr() {
            if (--(*count) == 0)
                delete ptr;
        }

    private:
        wibble * ptr;
        int * count;
}
