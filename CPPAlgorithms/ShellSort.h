//
// Created by kali on 12/1/22.
//

#ifndef INC_263PROJECT_SHELLSORT_H
#define INC_263PROJECT_SHELLSORT_H
#include <math.h>

class ShellSort {
public:
    static int insertionSortModified(int *list, int listLen, int start, int increment) {
        int count = 0;
        int n = listLen;
        //  <@  Must have a loop which compares each number in the sublist to each previous number in its sublist
        //      (starts at i + increment and ends when => n)
        for(int j = start + increment; j < n; j += increment) {
            //  <@  Inside this is where the insertion sort logic goes
            int newElement = list[j];
            int location = j - increment;
            count++;
            while(location >= 0 && list[location] > newElement && location + increment < listLen) {
                list[location + increment] = list[location];
                location = location - increment;
                count++;
            }
            list[location + increment] = newElement;
        }
        return count;
    };

    static int shellSort(int *list, int listLen) {
        int count = 0;
        int passes = (int) (std::log(listLen) / std::log(2));
        while(passes >= 1) {
            int increment = std::pow(2, passes - 1);
            for(int i = 0; i < increment; i++) {
                count += insertionSortModified(list, listLen, i, increment);
            }
            passes--;
        }
        return count;
    };
};

#endif //INC_263PROJECT_SHELLSORT_H
