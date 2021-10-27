#include <iostream>
template <typename Type>
void input (Type *array, int n) {
    for (int i = 0; i < n; ++i) {
        std::cin>>array[i];
    }
}
template<typename Type>
void output (Type *array, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout<<array[i];
    }
}

template<typename Type>
bool ordered (Type *arr, int n) {
    int flag = 0;
    for (int i = 0; i <n-1; ++i) {
        if (arr[i] > arr[i+1]) {
            flag++;
        }
    }
    if(flag != 0) {

        return false;
    } else {
        return true;
    }
}

//template<class T>
//class DynamicArray
//{
//public:
//    explicit DynamicArray(size_t capacity): data{new T[capacity]},size{0},capacity{capacity}{}
//    ~DynamicArray();
//    DynamicArray(const DynamicArray<T>& other);
//    DynamicArray& operator=(const DynamicArray& other);
//private:
//    T* data;
//    size_t size;
//    size_t capacity;
//};
//
//template<class T>
//DynamicArray<T>::~DynamicArray() {
//delete[] data;
//}
//
//template<class T>
//DynamicArray<T>::DynamicArray(const DynamicArray<T> &other) {
// data = new T[other.capacity];
// size =other.size;
// capacity = other.capacity;
//    for (int i = 0; i < other.size; ++i) {
//        data[i] = other.data[i];
//    }
//}
//
//template<class T>
//DynamicArray &DynamicArray<T>::operator=(const DynamicArray &other) {
//    DynamicArray<T> cpy{other}
//}


int main() {
    int n = 4;
    int *arr = new int[n] ;
    input(arr,n);
    output(arr,n);
    std::cout<<" "<< ordered(arr,n);


    return 0;
}
