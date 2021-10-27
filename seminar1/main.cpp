
#include <iostream>
///примерни
//n = 4 => 10 1 2 3 => sum = c1*1 + c1*1 c2*4 + c3*3 + c1*1 + c4*4
// n  = 8 => 10 1 2 3 4 5 6 7 => sum = c1*1 + c1*1 + c2*8 + c3*7 + c1*0 + c4*8
// n = 8 => 1 2 3 4 5 6 7 10 => sum = c1*1 + c1*1 + c2*8 + c3*7 + c1*7 + c4*8

//опростяване
// sum = c1 + c2*n + c3*(n-1) + c1 + c4*n

// sum = 2*c1 + c2*n + c3*n - c3 + c4*n

// sum = 3*c1 + (c2 +c3 +c4)*n - c3

// sum = n
// O(n)

// 100n + 300
// k1 = 100, k2 =300
// n

// c1 = времето за изпълнение на операция присвояване
// c2 = времето за изпълнение на операция сравение (<)
// c3 = веремето за изпълнение на операция сравенение (>)
// c4 = веремето за изпълнение на операция ++
template<typename T>
void findMax(T *array, int arrayLength) {
    // 1
    // 1
    // 1
    T localMax = array[0];
    // i < arrayLength: 4 //  ++i: 4

    // i < arrayLength: 8 + c3 * 7 + c1*0 //  ++i: 8
    // i < arrayLength: 8 + c3 * 7 + c1*0   //  ++i: 8


    for (int i = 1; i < arrayLength; ++i) {

        //c3 ---> // 3 // 7 // 7
        if (array[i] > localMax) {
            // 0
            // 0
            // 7
            localMax = array[i];
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////

// c1 = времето за изпълнение на операция присвояване
// c2 = времето за изпълнение на операция сравение (<)
// c3 = веремето за изпълнение на операция ++
// c4 = веремето за изпълнение на операция сравенение (>)
// c5 = времето за изпълнение на swap

/// arrayLength = 4 -> 5,4,6,1
//// i -> 1  /// i<arraylength   -> i=0,i=1,i=2,i=3 => 4 /// ++i -> 4
//// c1*1 c2*4 c3*4

/// j -> 1  /// i<arraylength-1  -> i=0,i=1,i=2    => 3 /// ++i -> 3
/// c1*1 c2*3 c3*3

/// -- i =0
///c4 => 5 > 4 => c5 -> 4,5,6,1
///c4 -> 5 > 6
///c4 -> 6 > 1 => c5 -> 4,5,1,6
/// -- i =1
///c4 => 4 > 5
///c4 -> 5 > 1 => c5 -> 4,1,5,6
///c4 -> 5 > 6
/// -- i =2
///c4 => 4 > 1 => c5 -> 1,4,5,6
///c4 -> 4 > 5
///c4 -> 5 > 6
/// -- i =3
///c4 => 1 > 4
///c4 -> 4 > 5
///c4 -> 5 > 6
//////// c4*12 , c5*4

////sum = c1*1 + c2*4 + c3*4 + c1*1 + c2*3 + c3*3 + c4*4 + c5*4



template<typename T>
void bubbleSort(T *array, int arrayLength) {
    for (int i = 0; i < arrayLength; ++i) {
        /// c1*1 c2*n c3*n
        for (int j = 0; j < arrayLength - 1; j++) {
            /// c1*1 c2*n-1 c3*(n-1)
            if (array[j] > array[j + 1]) { /// проверяваме текущя елемент е по-голям от следващия
            /// c4*n*(n-1)
                std::swap(array[j], array[j + 1]);
                ///c5*k(number of swaps)
            }
        }
    }
}
//// ------> sum = c1*1 + c1*1 + c2*n + c2*(n-1) + c3*n + c3*(n-1) + c4*n*(n-1) + c5*k
/// sum = 2*c1 + 2*c2*n - c2 +2*c3*n - c3  + c4*n^2 - c4*n + c*5*k
/// sum = c4*n^2 + (2*c2+ 2*c3 - c4)*n + 2*c1 - c2 - c3 + c*5*k
// sum = n^2 + n
// O(n^2)

template<typename T>
void selectionSort(T *array, int arrayLength) {
    for (int i = 0; i < arrayLength; ++i) {
        int index = i;
        for (int j = i + 1; j < arrayLength; j++) {
            if (array[j] < array[index])
                index = j;
        }
        std::swap(array[i], array[index]);
    }
}

template<typename T>
void insertionSort(T *array, int arrayLength) {
    for (int i = 1; i < arrayLength; ++i) {
        for (int idx = i; idx > 0 && array[idx] < array[idx - 1]; idx--) {
            std::swap(array[idx], array[idx - 1]);
        }
    }
}

template<typename T>
void display(T * array, int arrayLength) {
    for (int i = 0; i != arrayLength; ++i) {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
}

int main() {
    const int numbersLength = 5;
    int * numbers = new int[numbersLength];
    numbers[0] = 5;
    numbers[1] = 4;
    numbers[2] = 3;
    numbers[3] = 2;
    numbers[4] = 1;

//    bubbleSort(numbers, numbersLength);
//    selectionSort(numbers, numbersLength);
    insertionSort(numbers, numbersLength);
    display(numbers, numbersLength);


    delete[] numbers;
    return 0;
}

