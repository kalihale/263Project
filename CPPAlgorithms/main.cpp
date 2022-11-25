//
// Created by kali on 11/22/22.
//

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <sys/time.h>
#include <ctime>
#include "Sorts.h"

using std::cout; using std::endl;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;

int main(int argc, const char *argv[]) {
    const int RUNS = 1000;
    int arr[1000];
    int *comparisons = new int[1];

    long totalTime;
    long startTime;
    long endTime;

    // ／(^ㅅ^)＼ BubbleSort Tests
    totalTime = 0;
    for(int i = 0; i < RUNS; ++i) {
        for(int &j: arr) {
            j = rand() % 1000;
        }
        comparisons[0] = 0;

        startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        Sorts<int>::bubbleSort(arr, 1000);
        endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        totalTime += endTime - startTime;
    }

    std::cout << "BubbleSort Average Time: " << (double)totalTime / RUNS << std::endl;

//    // ／(^ㅅ^)＼ Insertion Sort Tests
//    totalTime = 0;
//    for(int i = 0; i < RUNS; ++i) {
//        for(int &j: arr) {
//            j = rand() % 1000;
//        }
//        comparisons[0] = 0;
//
//        startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
//        Sorts<int>::insertionSort(arr, 1000);
//        endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
//        totalTime += endTime - startTime;
//    }
//
//    std::cout << "InsertionSort Average Time: " << (double)totalTime / RUNS << std::endl;

//    // ／(^ㅅ^)＼ ShellSort Times
//    totalTime = 0;
//    for(int i = 0; i < RUNS; ++i) {
//        for(int &j: arr) {
//            j = rand() % 1000;
//        }
//        comparisons[0] = 0;
//
//        startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
//        Sorts<int>::shellSort(arr, 1000);
//        endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
//        totalTime += endTime - startTime;
//    }
//
//    std::cout << "ShellSort Average Time: " << (double)totalTime / RUNS << std::endl;

//    // ／(^ㅅ^)＼ RadixSort Times
//    totalTime = 0;
//    for(int i = 0; i < RUNS; ++i) {
//        for(int &j: arr) {
//            j = rand() % 1000;
//        }
//        comparisons[0] = 0;
//
//        startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
//        Sorts<int>::radixSort(arr, 1000);
//        endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
//        totalTime += endTime - startTime;
//    }
//
//    std::cout << "RadixSort Average Time: " << (double)totalTime / RUNS << std::endl;

//    // ／(^ㅅ^)＼ MergeSort Times
//    totalTime = 0;
//    for(int i = 0; i < RUNS; ++i) {
//        for(int &j: arr) {
//            j = rand() % 1000;
//        }
//        comparisons[0] = 0;
//
//        startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
//        Sorts<int>::mergeSort(arr, 1000, 0, 1000);
//        endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
//        totalTime += endTime - startTime;
//    }
//
//    std::cout << "MergeSort Average Time: " << (double)totalTime / RUNS << std::endl;

//    // ／(^ㅅ^)＼ QuickSort Times
//    totalTime = 0;
//    for(int i = 0; i < RUNS; ++i) {
//        for(int &j: arr) {
//            j = rand() % 1000;
//        }
//        comparisons[0] = 0;
//
//        startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
//        Sorts<int>::quickSortPivotFirst(arr, 0, 1000, comparisons);
//        endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
//        totalTime += endTime - startTime;
//    }
//
//    std::cout << "QuickSort Average Time: " << (double)totalTime / RUNS << std::endl;

    delete[] comparisons;
}