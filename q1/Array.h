class Array
{
    public:
        Array();
        Array(const int SIZE, const int value);
        Array(const int SIZE, const int* arr);
        Array(const Array& array);
        void add(const Array& array);
        void subtract(const Array& array);
        int multiply(const Array& array);
        void copy(const Array& array);
        int getSize();
        int* getData();
        void fill(const int value);
        void print();
    private:
        int* data;
        int size;
};