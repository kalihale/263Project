//
// Created by kali on 12/1/22.
//

#ifndef INC_263PROJECT_INSERTIONSORT_H
#define INC_263PROJECT_INSERTIONSORT_H

class InsertionSort {
public:
    static int insertionSort(int *list, int listLen) {
        int count = 0;
        int n = listLen;
        for(int i = 1; i < n; i++) {
            int newElement = list[i];
            int location = i - 1;
            count++;
            while(location >= 0 && list[location] > newElement) {
                list[location + 1] = list[location];
                location = location - 1;
                count++;
            }
            list[location + 1] = newElement;
        }
        return count;
    };
};

#endif //INC_263PROJECT_INSERTIONSORT_H
