//
// Created by kali on 11/22/22.
//

#include <iostream>
#include <cstdlib>
#include "Sorts.h"

int main(int argc, const char * argv[]) {
    int arr[1000];
    // ／(^ㅅ^)＼ TODO: Find junk data
    for(int & i : arr) {
        i = rand() % 1000;
    }

    int* comparisons = new int[1];

    comparisons[0] = 0;

    // ／(^ㅅ^)＼ Working:
//    Sorts<int>::bubbleSort(arr, 1000);
//    Sorts<int>::insertionSort(arr, 1000);
//    Sorts<int>::shellSort(arr, 1000);
//    Sorts<int>::mergeSort(arr, 1000, 0, 1000);
//    Sorts<int>::quickSortPivotFirst(arr, 0, 1000, comparisons);
//    Sorts<int>::quickSortPivotLast(arr, 0, 1000, comparisons);
    Sorts<int>::quickSortPivotRandom(arr, 0, 1000, comparisons);

//    Sorts<int>::radixSort(arr, 1000, 3);

    std::cout << comparisons[0] << std::endl;

    for(int i : arr) {
        std::cout << i << std::endl;
    }
}