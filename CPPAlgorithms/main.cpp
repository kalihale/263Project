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
using std::chrono::system_clock;

int main(int argc, const char *argv[]) {
    const int RUNS = 1000;
    const int LEN = 1000;
    int arr[LEN];
    int *comparisons = new int[1];
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, LEN);

    long totalTime;
    std::chrono::time_point<system_clock, system_clock::duration> startTime;
    std::chrono::time_point<system_clock, system_clock::duration> endTime;

    // ／(^ㅅ^)＼ BubbleSort Tests
    totalTime = 0;
    for(int i = 0; i < RUNS; ++i) {
        for(int &j: arr) {
            j = dist(mt);
        }

        startTime = std::chrono::high_resolution_clock::now();
        Sorts<int>::bubbleSort(arr, LEN);
        endTime = std::chrono::high_resolution_clock::now();
        totalTime += std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    }

    std::cout << "BubbleSort Average Time: " << (double)totalTime / RUNS << std::endl;

//    // ／(^ㅅ^)＼ Insertion Sort Tests
//    totalTime = 0;
//    for(int i = 0; i < RUNS; ++i) {
//        for(int &j: arr) {
//            j = dist(mt);
//        }
//
//        startTime = std::chrono::high_resolution_clock::now();
//        Sorts<int>::insertionSort(arr, 1000);
//        endTime = std::chrono::high_resolution_clock::now();
//        totalTime += std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
//    }
//
//    std::cout << "InsertionSort Average Time: " << (double)totalTime / RUNS << std::endl;
//
//    // ／(^ㅅ^)＼ ShellSort Times
//    totalTime = 0;
//    for(int i = 0; i < RUNS; ++i) {
//        for(int &j: arr) {
//            j = dist(mt);
//        }
//
//        startTime = std::chrono::high_resolution_clock::now();
//        Sorts<int>::shellSort(arr, LEN);
//        endTime = std::chrono::high_resolution_clock::now();
//        totalTime += std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
//    }
//
//    std::cout << "ShellSort Average Time: " << (double)totalTime / RUNS << std::endl;

//    // ／(^ㅅ^)＼ RadixSort Times
//    totalTime = 0;
//    for(int i = 0; i < RUNS; ++i) {
//        for(int &j: arr) {
//            j = dist(mt);
//        }
//
//        startTime = std::chrono::high_resolution_clock::now();
//        Sorts<int>::radixSort(arr, 1000);
//        endTime = std::chrono::high_resolution_clock::now();
//        totalTime += std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();
//    }
//
//    std::cout << "RadixSort Average Time: " << (double)totalTime / RUNS << std::endl;

//    // ／(^ㅅ^)＼ MergeSort Times
//    totalTime = 0;
//    for(int i = 0; i < RUNS; ++i) {
//        for(int &j: arr) {
//            j = dist(mt);
//        }
//
//        startTime = std::chrono::high_resolution_clock::now();
//        Sorts<int>::mergeSort(arr, LEN, 0, LEN);
//        endTime = std::chrono::high_resolution_clock::now();
//        totalTime += std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
//    }
//
//    std::cout << "MergeSort Average Time: " << (double)totalTime / RUNS << std::endl;
//
//    // ／(^ㅅ^)＼ QuickSort Times
//    totalTime = 0;
//    for(int i = 0; i < RUNS; ++i) {
//        for(int &j: arr) {
//             j = dist(mt);
//        }
//        comparisons[0] = 0;
//
//        startTime = std::chrono::high_resolution_clock::now();
//        Sorts<int>::quickSortPivotFirst(arr, 0, LEN, comparisons);
//        endTime = std::chrono::high_resolution_clock::now();
//        totalTime += std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
//    }
//
//    std::cout << "QuickSort Average Time: " << (double)totalTime / RUNS << std::endl;

//        for(int &j: arr) {
//            j = dist(mt);
//        }
//
//        Sorts<int>::bubbleSort(arr, 1000);

//    for(int &j: arr) {
//        j = dist(mt);
//    }
//
//    Sorts<int>::insertionSort(arr, 1000);

//    for(int &j: arr) {
//        j = dist(mt);
//    }
//
//    Sorts<int>::shellSort(arr, 1000);

//    for(int &j: arr) {
//        j = dist(mt);
//    }
//
//    Sorts<int>::mergeSort(arr, 1000, 0, 1000);

//    for(int &j: arr) {
//        j = dist(mt);
//    }
//
//    Sorts<int>::quickSortPivotFirst(arr, 1000, 0, comparisons);

    delete[] comparisons;
}