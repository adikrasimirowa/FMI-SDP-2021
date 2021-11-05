//
// Created by adi on 27.10.21 г..
//

#ifndef SEMINAR3_DARRAY_H
#define SEMINAR3_DARRAY_H
template <typename Type>
class DArray {
private:
    Type* data;
    size_t size;
    size_t capacity;

private:
    void copy ( const DArray &other);

public:
    DArray();
    explicit DArray(const size_t& size);
    DArray(const DArray& other);
    DArray &operator=(const DArray &other);
    ~DArray();

public:
    ///промяна на капацитета, за да бъде достатъчен
    void reserve(const size_t& newCapacity);

    ///Преозмерява вектора. Прави размерът му newSize елемената
    void resize(size_t newSize);

    ///Добавя елемент в края на масива
    void pushBack(const Type& values);

    ///Премахва елемент от края на масива
    void popBack();

    void print();

public:

    /// заделя памет т с капацитет capacity
    /// capacity - размер на заделената памет
    /// return - указател към заделената памет
    static Type* allocateMemory(size_t capacity);

    ///конструира обекти от тип T посредстеом конструктор
    /// за копиране върху паметта, определена орт обхвата begin до end
    ///begin - указател ктм начало на обхвата
    /// end - указател към края на обхвата
    /// fillValue - сстойността с която да бъде запълнен масива
    static void constructCopyRange(Type* begin, Type* end, Type* fillValue );

    ///конструира обекти от тип T посредстеом конструктор
    /// по подразбиране върху паметта, определена орт обхвата begin до end
    ///begin - указател ктм начало на обхвата
    /// end - указател към края на обхвата
    static void constructRange(Type* begin, Type*end);

    static void destructRange(Type* begin, Type* end);

    static  void destructAndDeleteRange(Type* begin, Type* end);
};

///COPY
template<typename Type>
void DArray<Type>::copy(const DArray<Type> &other) {
    this->size = other.size;
    this->capacity = other.capacity;
    this->data = allocateMemory(other.capacity);
    constructCopyRange(other.data,other.data + other.size, this->data);
}

///CONSTRUCTORS
template<typename Type>
DArray<Type>::DArray() : data(allocateMemory(8)),size(0),capacity(8) {
    try {
        constructRange(this->data, this->data + this->capacity);
    } catch (...) {
        destructAndDeleteRange(this->data, this->data + this->size);
        throw ;
    }

}
template<typename Type>
DArray<Type>::DArray(const size_t &size) : data(allocateMemory(size)),size(size), capacity(size) {
        constructRange(this->data, this->data+size);
}
template<typename Type>
DArray<Type>::DArray(const DArray &other) {
    try {
        this->copy(other);
    } catch (...) {
        other->~DArray();
        throw ;
    }

}

template<typename Type>
DArray<Type> &DArray<Type>::operator=(const DArray &other) {
    if(this != other) {
        this->destructAndDeleteRange(this->data, this->data + this->size);
        this->copy(other);
    }
    return *this;
}


template<typename Type>
DArray<Type>::~DArray() {
    destructAndDeleteRange(this->data, this->data + this->size);
}



template<typename Type>
Type *DArray<Type>::allocateMemory(const size_t _capacity) {
        return static_cast<Type*>(operator new(sizeof(Type)*_capacity));
}

template<typename Type>
void DArray<Type>::constructCopyRange(Type *begin, Type *end, Type* fillValue) {
    while (begin != end) {
        new((void*)fillValue) Type(*begin);
        ++begin;
        ++fillValue;
    }
}

template<typename Type>
void DArray<Type>::constructRange(Type *begin, Type *end) {
    while (begin != end) {
        new((void*)begin) Type();
        ++begin;
    }
}

template<typename Type>
void DArray<Type>::destructRange(Type *begin, Type *end) {
    while (begin != end) {
        begin->~Type();
        ++begin;
    }
}

template<typename Type>
void DArray<Type>::destructAndDeleteRange(Type *begin, Type *end) {
    destructRange(begin, end);
    operator delete (begin);
}

///RESERVE
template<typename Type>
void DArray<Type>::reserve(const size_t &newCapacity) {
    //ако newCapacity e по-голям от текущия capacity, се разпределя ново място за съхранение
    // не променя размера на вектора
    if(newCapacity > this->capacity) {
        Type* _data = allocateMemory(newCapacity);
        constructCopyRange(this->data, this->data + this->size , _data);
        destructAndDeleteRange(this->data, this->data + this->size);
        this->data = _data;
        this->capacity = newCapacity;
    }
}

///RESIZE
template<typename Type>
void DArray<Type>::resize(const size_t newSize) {
    //ако новият размер е по-малък от текущият размер,крайните елементи се трият
    if(newSize <= this->size) {
        destructRange(this->data + newSize, this->data + this->size);
        this->size = newSize;
        return;
    }
    //ако новият размер е по-малък от текущият размер,крайните елементи се трият
    if(newSize <= this->capacity ) {
        constructRange(this->data + this->size, this->data + newSize);
        this->size = newSize;
        return;
    }

    ///2 - факторна стойност
    size_t newCapacity = newSize;
    size_t defaultGrowthCapacity = size > 0? size * 2 :newSize;
    while (newSize < defaultGrowthCapacity) {
        defaultGrowthCapacity *= 2;
    }
    if (newCapacity < defaultGrowthCapacity) {
        newCapacity = defaultGrowthCapacity;
    }


    Type* _data = allocateMemory(newCapacity);
    constructCopyRange(this->data, this->data + this->size , _data);
    destructAndDeleteRange(this->data, this->data + this->size);
    this->data = _data;
    this->capacity = newCapacity;
    this->size = newSize;
}

///PUSH BACK
template<typename Type>
void DArray<Type>::pushBack( const Type &values) {
    if(this->size >= this->capacity) {
        reserve((this->capacity*2));
    }
    new ((void*) (this->data + this->size))  Type(values);
    this->size++;
}

///POP BACK
template<typename Type>
void DArray<Type>::popBack() {
    if(this->size == 0) {
        return;
    }
    destructRange(this->data + this->size - 1, this->data + this->size);
    this->size--;
}

///PRINT
template<typename Type>
void DArray<Type>::print() {
    for (int i = 0; i < this->size ; ++i) {
        std::cout<< this->data[i]<<std::endl;
    }
}

#endif //SEMINAR3_DARRAY_H
