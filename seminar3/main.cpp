#include <iostream>
#include "DArray.h"
int main() {
    ///така не се конструира обект , заделя се само памет / размер в байтове
    //DArray<int>* array= (DArray<int>*)(operator new(sizeof(DArray<int>)));
    DArray<int>* array= (DArray<int>*)(operator new(sizeof(DArray<int>)));
    new(array) DArray<int>(); /// създаваме обекта в/у дадената памет

    DArray<int>* arrPointer = static_cast<DArray<int>*>(array);
//    int* arr2 = new int[10];
//
//    arrPointer->resize(1);

    return 0;
}
