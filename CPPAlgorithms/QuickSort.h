//
// Created by kali on 12/1/22.
//

#ifndef INC_263PROJECT_QUICKSORT_H
#define INC_263PROJECT_QUICKSORT_H
#include <cmath>
#include <random>

class QuickSort {
public:
    static int quickSortPivotFirst(int *list, int first, int last, int *comparisons) {
        int count = 0;
        int pivot;
        if(first < last) {
            pivot = QuickSort::pivot(first, list, first, last, comparisons);
            quickSortPivotFirst(list, first, pivot - 1, comparisons);
            quickSortPivotFirst(list, pivot + 1, last, comparisons);
        }
        return count;
    };

    static int quickSortPivotLast(int *list, int first, int last, int *comparisons) {
        int count = 0;
        int pivot;
        if(first < last) {
            pivot = QuickSort::pivot(last, list, first, last, comparisons);
            quickSortPivotLast(list, first, pivot - 1, comparisons);
            quickSortPivotLast(list, pivot + 1, last, comparisons);
        }
        return count;
    };

    static int quickSortPivotRandom(int *list, int first, int last, int *comparisons) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(first, last);
        int count = 0;
        int pivot;
        if(first < last) {
            pivot = QuickSort::pivot(dist(mt), list, first, last, comparisons);
            quickSortPivotRandom(list, first, pivot - 1, comparisons);
            quickSortPivotRandom(list, pivot + 1, last, comparisons);
        }
        return count;
    };

    static int pivot(int pivot, int *list, int left, int right, int *comparisons) {
        int temp = list[right];
        list[right] = list[pivot];
        list[pivot] = temp;
        int i = left;

        for(int j = i; j < right; j++) {
            comparisons[0]++;
            if(list[j] < list[right]) {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
                i++;
            }

        }
        temp = list[i];
        list[i] = list[right];
        list[right] = temp;
        return i;
    }
};

#endif //INC_263PROJECT_QUICKSORT_H
