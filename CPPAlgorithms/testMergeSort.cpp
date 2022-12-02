//
// Created by kali on 12/2/22.
//

#include <iostream>
#include <chrono>
#include <random>
#include "MergeSort.h"

using std::cout; using std::endl;
using std::chrono::duration_cast;
using std::chrono::system_clock;

int main(int argc, const char *argv[]) {
    const int RUNS = 1000;
    const int LEN = 1000;
    int arr[LEN];
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, LEN);

    long totalTime;
    std::chrono::time_point<system_clock, system_clock::duration> startTime;
    std::chrono::time_point<system_clock, system_clock::duration> endTime;

    // ／(^ㅅ^)＼ MergeSort Times
    totalTime = 0;
    for(int i = 0; i < RUNS; ++i) {
        for(int &j: arr) {
            j = dist(mt);
        }

        startTime = std::chrono::high_resolution_clock::now();
        int* count = 0;
        MergeSort::mergeSort(arr, LEN, 0, LEN, count);
        endTime = std::chrono::high_resolution_clock::now();
        totalTime += std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    }

    std::cout << "MergeSort Average Time: " << (double)totalTime / RUNS << std::endl;
}