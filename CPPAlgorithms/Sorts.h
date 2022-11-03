//
// Created by kali on 11/2/22.
//

#ifndef INC_263PROJECT_SORTS_H
#define INC_263PROJECT_SORTS_H
#include <string>
#include <cmath>
#include <random>


class Sorts {
public:
    static int bubbleSort(int* list, int listLen) {
        int count = 0;
        int numberOfPairs = listLen;
        bool swappedElements = true;
        int temp;
        while(swappedElements) {
            numberOfPairs--;
            swappedElements = false;
            for(int i = 0; i < numberOfPairs; ++i) {
                count++;
                if(list[i] > list[i + 1]){
                    temp = list[i];
                    list[i] = list[i + 1];
                    list[i + 1] = temp;
                    swappedElements = true;
                }
            }
        }
        return count;
    };

    static int insertionSort(int* list, int listLen) {
        int count = 0;
        int n = listLen;
        for (int i = 1; i < n; i++)
        {
            int newElement = list[i];
            int location = i - 1;
            count++;
            while (location >= 0 && list[location] > newElement)
            {
                list[location + 1] = list[location];
                location = location - 1;
                count++;
            }
            list[location + 1] = newElement;
        }
        return count;
    };

    static int insertionSortModified(int* list, int listLen, int start, int increment) {
        int count = 0;
        int n = listLen;
        //  <@  Must have a loop which compares each number in the sublist to each previous number in its sublist
        //      (starts at i + increment and ends when => n)
        for(int j = start + increment; j < n; j += increment)
        {
            //  <@  Inside this is where the insertion sort logic goes
            int newElement = list[j];
            int location = j - increment;
            count++;
            while (location >= 0 && list[location] > newElement && location + increment < list.length)
            {
                list[location + increment] = list[location];
                location = location - increment;
                count++;
            }
            list[location + increment] = newElement;
        }
        return count;
    };
    static int shellSort(int* list, int listLen) {
        int count = 0;
        int passes = (int)(std::log(listLen)/std::log(2));
        while(passes >= 1)
        {
            int increment = std::pow(2, passes - 1);
            for(int i = 0; i < increment; i++)
            {
                count += insertionSortModified(list, listLen, i, increment);
            }
            passes--;
        }
        return count;
    };

    static int radixSort(int* list, int listLen, int keySize) {
        //  <@  Create buckets
        LinkedList<Integer>[] buckets = new LinkedList[10];
        GenericCombineBuckets gcb = new GenericCombineBuckets();
        //  <@  Initialize linkedlists in array "buckets"
        for(int i = 0; i < buckets.length; i++)
        {
            buckets[i] = new LinkedList<>();
        }
        //  <@  Initialize shift at 1
        int shift = 1;
        //  <@  Up until the largest digit (starting with the ones digit for all numbers)
        //      Note: Once the number of digits in shift is larger than the number of digits in a number,
        //      (list[j] / shift) % 10 will return 0, which will put the number in the 0 bucket
        for(int i = 1; i <= keySize; i++)
        {
            //  <@  For the entire list, sort the digit in question into buckets 0-9
            for(int j = 0; j < list.length; j++)
            {
                buckets[(list[j] / shift) % 10].add(list[j]);
            }
            //  <@  Combine the buckets (using a generic class)
            //      Multiply shift by 10
            gcb.CombineBuckets(list, buckets);
            shift *= 10;
        }
        return *list;
    };

    static std::string* radixSort(std::string* list, int listLen, int keySize) {
        //  <@  Create buckets
        LinkedList<String>[] buckets = new LinkedList[26];
        GenericCombineBuckets gcb = new GenericCombineBuckets();
        //  <@  Initialize
        for(int i = 0; i < buckets.length; i++)
        {
            buckets[i] = new LinkedList<>();
        }
        //  <@  Initialize shift
        int shift = 1;
        //  <@  Loops until we're done with the longest word
        for(int i = 1; i <= keySize; i++)
        {
            //  <@  Loop through the entire list looking at a certain index
            for(int j = 0; j < list.length; j++)
            {
                //  <@  If the last index of the word is a smaller number than the index we're looking at,
                //      put the word in the bucket for 'a' because smaller words come first in the dictionary
                //      (eg. "pea" always comes before "peacock", so we can use 'a' as a placeholder)
                if (list[j].length() - 1 < keySize - shift)
                {
                    buckets[0].add(list[j]);
                }
                    //  <@  Else evaluate the character at that index
                else
                {
                    buckets[list[j].charAt(keySize - shift) - 97].add(list[j]);
                }
            }
            //  <@  Combine buckets (using a generic class) and increment shift (we are not dividing numbers so
            //      we're shifting one to the left this time)
            gcb.CombineBuckets(list, buckets);
            shift++;
        }
        return list;
    };

    static int mergeSort(int* list, int listLen, int first, int last) {
        int middle;
        int count = 0;
        if(first < last)
        {
            middle = (first + last)/2;
            count += mergeSort(list, listLen, first, middle);
            count += mergeSort(list, listLen, middle+1, last);
            count += mergeLists(list, listLen, first, middle, middle+1, last);
        }
        return count;
    };

    static int mergeLists(int* list, int listLen, int start1, int end1, int start2, int end2) {
        int count = 0;
        int* result = new int[listLen];
        int finalStart = start1;
        int finalEnd = end2;
        int indexC = 0;
        while(start1 <= end1 && start2 <= end2)
        {
            count++;
            if(list[start1] < list[start2])
            {
                result[indexC] = list[start1];
                start1++;
            }
            else
            {
                result[indexC] = list[start2];
                start2++;
            }
            indexC++;
        }
        if(start1 <= end1)
        {
            for(int i = start1; i <= end1; i++)
            {
                result[indexC] = list[i];
                indexC++;
            }
        }
        else
        {
            for(int i = start2; i <= end2; i++)
            {
                result[indexC] = list[i];
                indexC++;
            }
        }
        indexC = 0;
        for(int i = finalStart; i <= finalEnd; i++)
        {
            list[i] = result[indexC];
            indexC++;
        }
        return count;
    };

    static int quickSortPivotFirst(int* list, int first, int last, int* comparisons)
    {
        int count = 0;
        int pivot;
        if(first < last)
        {
            pivot = Sorts::pivot(first, list, first, last, comparisons);
            quickSortPivotFirst(list, first, pivot - 1, comparisons);
            quickSortPivotFirst(list, pivot + 1, last, comparisons);
        }
        return count;
    };

    static int quickSortPivotLast(int* list, int first, int last, int* comparisons)
    {
        int count = 0;
        int pivot;
        if(first < last)
        {
            pivot = Sorts::pivot(last, list, first, last, comparisons);
            quickSortPivotLast(list, first, pivot - 1, comparisons);
            quickSortPivotLast(list, pivot + 1, last, comparisons);
        }
        return count;
    };

    static int quickSortPivotRandom(int* list, int first, int last, int* comparisons) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(first, last);
        int count = 0;
        int pivot;
        if(first < last) {
            pivot = Sorts::pivot(dist(mt), list, first, last, comparisons);
            quickSortPivotRandom(list, first, pivot - 1, comparisons);
            quickSortPivotRandom(list, pivot + 1, last, comparisons);
        }
        return count;
    };

    static int pivot(int pivot, int* list, int left, int right, int* comparisons)
    {
        int temp = list[right];
        list[right] = list[pivot];
        list[pivot] = temp;
        int i = left;

        for(int j = i; j < right; j++)
        {
            comparisons[0]++;
            if(list[j] < list[right])
            {
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


#endif //INC_263PROJECT_SORTS_H
