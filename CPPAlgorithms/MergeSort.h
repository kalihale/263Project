//
// Created by kali on 12/1/22.
//

#ifndef INC_263PROJECT_MERGESORT_H
#define INC_263PROJECT_MERGESORT_H

class MergeSort {
public:
    static void mergeSort(int *list, int listLen, int first, int last, int* count) {
        int middle;
        if(first < last) {
            middle = (first + last) / 2;
            mergeSort(list, listLen, first, middle, count);
            mergeSort(list, listLen, middle + 1, last, count);
            mergeLists(list, listLen, first, middle, middle + 1, last, count);
        }
    };

    static void mergeLists(int* list, int listLen, int start1, int end1, int start2, int end2, int* count) {
        int* result = new int[listLen];
        int finalStart = start1;
        int finalEnd = end2;
        int indexC = 0;
        while(start1 <= end1 && start2 <= end2) {
            count++;
            if(list[start1] < list[start2]) {
                result[indexC] = list[start1];
                start1++;
            } else {
                result[indexC] = list[start2];
                start2++;
            }
            indexC++;
        }
        if(start1 <= end1) {
            for(int i = start1; i <= end1; i++) {
                result[indexC] = list[i];
                indexC++;
            }
        } else {
            for(int i = start2; i <= end2; i++) {
                result[indexC] = list[i];
                indexC++;
            }
        }
        indexC = 0;
        for(int i = finalStart; i <= finalEnd; i++) {
            list[i] = result[indexC];
            indexC++;
        }
        delete[] result;
    };
};

#endif //INC_263PROJECT_MERGESORT_H
