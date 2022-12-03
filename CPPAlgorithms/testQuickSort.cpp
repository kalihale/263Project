//
// Created by kali on 12/2/22.
//

#include <iostream>
#include <chrono>
#include <random>
#include "QuickSort.h"

using std::cout; using std::endl;
using std::chrono::duration_cast;
using std::chrono::steady_clock;

int main(int argc, const char *argv[]) {
    const int RUNS = 1000;
    const int LEN = 1000;
    int arr[LEN];
    int *comparisons = new int[1];
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, LEN);

    long totalTime;
    std::chrono::time_point<steady_clock, steady_clock::duration> startTime;
    std::chrono::time_point<steady_clock, steady_clock::duration> endTime;

    // ／(^ㅅ^)＼ QuickSort Times
    totalTime = 0;
    for(int i = 0; i < RUNS; ++i) {
        for(int &j: arr) {
            j = dist(mt);
        }
        comparisons[0] = 0;

        startTime = std::chrono::steady_clock::now();
        QuickSort::quickSortPivotFirst(arr, 0, LEN, comparisons);
        endTime = std::chrono::steady_clock::now();
        totalTime += std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    }

    std::cout << "QuickSort Average Time: " << (double)totalTime / RUNS << std::endl;
}
