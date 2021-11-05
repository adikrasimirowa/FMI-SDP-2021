#include <iostream>
#include "DArray.h"
int main() {
    ///така не се конструира обект , заделя се само памет / размер в байтове
    DArray<int>* array= (DArray<int>*)(operator new(sizeof(DArray<int>)));
    new(array) DArray<int>(); /// създаваме обекта в/у дадената памет

    DArray<int>* arrPointer = static_cast<DArray<int>*>(array);

     arrPointer->pushBack(1);
     arrPointer->print();
    return 0;
}
