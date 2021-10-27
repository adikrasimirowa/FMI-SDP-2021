#include <iostream>
#include "DynamicArray.h"

//class  Student {
//public:
//    Student()=delete; ///забраняваме да предостява дефаутен конструктор
////    Student(){
////
////    }
//};


int main() {

DynamicArray<int> array;
array.add(4);

array.add(6);
array.print();
array.remove(0);
array.print();

DynamicArray<double> array2;
array2.add(4.8);
array2.print();

    return 0;
}
