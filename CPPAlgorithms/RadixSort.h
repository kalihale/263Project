//
// Created by kali on 12/1/22.
//

#ifndef INC_263PROJECT_RADIXSORT_H
#define INC_263PROJECT_RADIXSORT_H
#include "DoubleLinkedList.h"

template <class T> class RadixSort {
public:
    struct Node {
        T data;
        struct Node *next = nullptr;
    };

    T *list;
    Node *buckets;

    class GenericCombineBuckets {
    public:
        T* list;
        DoubleLinkedList<T>* buckets;

        // ／(^ㅅ^)＼ buckets is an array of starting nodes for linked lists
        //           list is the full array of elements
        //           listlen is the length of the list
        //           numBuckets is the number of linkedlists in buckets
        void combineBuckets(T *list, DoubleLinkedList<int>*buckets, int listlen, int numBuckets) {
            this->list = list;
            this->buckets = buckets;
            int j = 0;
            for(int i = 0; i < numBuckets; ++i) {
                while(!buckets[i].isEmpty()) {
                    this->list[j] = (T) buckets[i].remove(0);
                    j++;
                }
            }
        }
    };
    static int radixSort(int *list, int listLen, int keySize) {
        //  <@  Create buckets
        auto* buckets = new DoubleLinkedList<int>[10];
        auto *gcb = new GenericCombineBuckets();
        //  <@  Initialize shift at 1
        int shift = 1;
        //  <@  Up until the largest digit (starting with the ones digit for all numbers)
        //      Note: Once the number of digits in shift is larger than the number of digits in a number,
        //      (list[j] / shift) % 10 will return 0, which will put the number in the 0 bucket
        for(int i = 1; i <= keySize; i++) {
            //  <@  For the entire list, sort the digit in question into buckets 0-9
            for(int j = 0; j < listLen; j++) {
                buckets[(list[j] / shift) % 10].add(list[j]);
            }
            //  <@  Combine the buckets (using a generic class)
            //      Multiply shift by 10
            gcb->combineBuckets(list, buckets, 1000, 10);
            shift *= 10;
        }
        delete[] buckets;
        delete gcb;
        return 1;
    };
};

#endif //INC_263PROJECT_RADIXSORT_H
