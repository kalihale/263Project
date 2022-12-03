# CMPSC 263 Project

By Kali Hale and Aaron Jimenez

## Overview

Java, C++, and Python are three of the five most popular programming languages [in use today](https://spectrum.ieee.org/top-programming-languages-2022). Using their most common runtime implementations, these languages function very differently during runtime - for example, Java and Python runtimes use garbage-collection, while the most popular C++ compilers require the programmer to free memory manually. However, what may be well-suited for one situation may be remarkably ill-suited for another. In order to choose the best language and runtime implementation for a project, we must first know what the limitations are for each. While we may understand technically what these differences should mean for the programmer, it is useful to gain a practical understanding of these differences. To get a baseline understanding of the practical differences between the languages, we have implemented several well-known sorting algorithms in Java, C++, and Python and compared real-time runtimes and memory usage for each when using the same hardware.

## Computer Specification
    * CPU: AMD Ryzen 5 5600 (x86-64, 6-Core, 12-Thread, Base Clock: 3.5GHz, no iGPU)
    * Memory: 32 GB DDR4
    * GPU: Nvidia RTX 3060
    * OS: Pop!_OS 22.04 LTS (Based on Ubuntu 22.04 LTS)
    
    
## Resources
* [memory_profiler](https://www.geeksforgeeks.org/monitoring-memory-usage-of-a-running-python-program/)
* [IntelliJ profiler tutorial](https://www.youtube.com/watch?v=OQcyAtukps4)


## Profiling Instructions

**All commands assume you are in the "263Project" folder.**

### Python

Make sure you have the `cProfiler` and `memory-profiler` Python libraries installed.

#### Run Time Profiler
1. Make sure all in instances of `from memory_profiler import profile` and `@profile` are commented out in `./PythonAlgorithms/*.py`
2. Run `./PythonAlgorithms/run_time.py` to obtain the times for 100 runs for each algorithim
3. Run `./PythonAlgorithms/outputs/stats_averager.py` to obtain the average run time for each algorithm. Result will be stored in `./PythonAlgorithms/outputs/runtimes.csv`

#### Memory Profiler
1. Make sure all in instances of `from memory_profiler import profile` and `@profile` are **uncommented** out in `./PythonAlgorithms/*.py`
2. Run `./PythonAlgorithms/mem_test.py`
3. Memory usage files for each algorithm will be store in `./PythonAlgorithms/outputs/MemoryOutputs/<algorithm>.py.dat`. Search for the largest value

### Java

#### Run Time Profiler
1. Run `./JavaAlgorithms/<algorithm>Test.java` to obtain an average runtime value as a program output

#### Memory Profiler
1. Run each test file, `./JavaAlgorithms/<algorithm>Test.java`, with the JetBrains profiler in their Intelij IDEA IDE
2. Open the saved snapshot for each algorithm and go the `call tree` tab
3. On the `Show` dropdown menu on the upper right, select `Memory Allocation`
4. Search for the `main` method

### C++

#### Run Time Profiler
1. Compile with `g++ -O3 -o <programName> ./CPPAlgorithms/test<algorithm>Sort.cpp`
2. Run with `./<outputName>`
3. Average runtime will output on commandline

#### Memory Profiler
1. Install Valgrind Massif
2. Compile with `g++ -O3 -o <programName> ./CPPAlgorithms/test<algorithm>Sort.cpp`
3. Run `valgrind --tool=massif --massif-out-file=<massifFile> <programName>`
4. Run `ms_print <massifFile> > <outputfile>.txt`
   - The output will be saved to `<outputfile>.txt` and will show the graph of memory usage over time
   - Line 33 will be labelled "Detailed snapshots" and will have a list of snapshot numbers. One of them will be labelled "(peak)" - this is the snapshot which recorded the peak memory usage
   - Scroll down to find that snapshot and find the total amount of memory in use in bytes and the useful-heap in bytes
