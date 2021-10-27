//
// Created by adi on 19.10.21 г..
//

#ifndef SEMINAR2_DYNAMICARRAY_H
#define SEMINAR2_DYNAMICARRAY_H

template <typename Type>
class DynamicArray {
private:
    Type *data;
    size_t size;
    static size_t capacity;
    /// size <= capacity

public:
    DynamicArray();
    //explicit  DynamicArray(size_t capacity = 16);
    DynamicArray(const DynamicArray<Type>& other);
    DynamicArray<Type>& operator=(const DynamicArray<Type>& other);
    ~DynamicArray();

public:
    void add(const Type& elem);
    void remove(unsigned index);
    void popBack();
    void print();

private:
    void destroy();
    void copy(const DynamicArray<Type>& other);
    void resize();


//    void reserve(const size_t newSize);
//    void add(const Type& elem, size_t pos);

//    void clear();
//    Type getElm(size_t) const;
//    void setElm(size_t,const Type&);
//    bool  operator==(const DynamicArray<Type>&);
//    Type& operator[](size_t);

};

///Constructors
//template<typename Type>
//DynamicArray<Type>::DynamicArray() :data(nullptr),size(0){}

//template<typename Type>
//DynamicArray<Type>::DynamicArray(const size_t &size) {
//  this->size = size;
//  this->capacity = size;
//  this->data = new Type[this->size]; // по подразбиране те са равни
//}

template <typename Type>
DynamicArray<Type>::DynamicArray() {
    this->size = 0;
    this->capacity = 0;
    this->data = new Type[this->size];
}

template<typename Type>
DynamicArray<Type>::DynamicArray(const DynamicArray<Type> &other) {

    this->copy(other);
}

template<typename Type>
DynamicArray<Type> &DynamicArray<Type>::operator=(const DynamicArray<Type> &other) {

    if (this != other) {
        this->destroy();
        this->copy(other);
    }
    return *this;
}

template<typename Type>
DynamicArray<Type>::~DynamicArray() {
    this->destroy();
}

/// DELETE DATA
template<typename Type>
void DynamicArray<Type>::destroy() {
    delete [] this->data;

}
/// COPY
template<typename Type>
void DynamicArray<Type>::copy(const DynamicArray<Type> &other) {
    this->size = other.size;
    this->capacity = other.capacity;
    this->data = new Type[this->capacity];

    for (int i = 0; i < other.size; ++i) {
        this->data[i] = other.data[i];
    }
}
///RESIZE
template<typename Type>
void DynamicArray<Type>::resize() {
    this->capacity *=2;
    Type* temp = new Type[this->capacity];
    for (int i = 0; i < this->size ; ++i) {
        temp[i] = this->data[i];
    }
    destroy();
    this->data = temp;

}

///ADD
template<typename Type>
void DynamicArray<Type>::add(const Type &elem) {
    if (this->size == this->capacity) {
        this->resize();
    }
    this->data[this->size] = elem;
    this->size++;

}
///REMOVE
template<typename Type>
void DynamicArray<Type>::remove(unsigned int index) {
    for (unsigned int i = index; i < this->size-1; ++i) {
        this->data[i] = this->data[i+1];
    }
    this->size--;
}

/// POP-BACK
template<typename Type>
void DynamicArray<Type>::popBack() {
    --this->size;
}
///PRINT
template<typename Type>
void DynamicArray<Type>::print() {
    for (int i = 0; i <this->size ; ++i) {
        std::cout<<data[i]<<" ";
    }
}

#endif //SEMINAR2_DYNAMICARRAY_H
