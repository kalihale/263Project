//
// Created by kali on 12/1/22.
//

#ifndef INC_263PROJECT_BUBBLESORT_H
#define INC_263PROJECT_BUBBLESORT_H

class BubbleSort {
public:
    static int bubbleSort(int *list, int listLen) {
        int count = 0;
        int numberOfPairs = listLen;
        bool swappedElements = true;
        int temp;
        while(swappedElements) {
            numberOfPairs--;
            swappedElements = false;
            for(int i = 0; i < numberOfPairs; ++i) {
                count++;
                if(list[i] > list[i + 1]) {
                    temp = list[i];
                    list[i] = list[i + 1];
                    list[i + 1] = temp;
                    swappedElements = true;
                }
            }
        }
        return count;
    };
};

#endif //INC_263PROJECT_BUBBLESORT_H
