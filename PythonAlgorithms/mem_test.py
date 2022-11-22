import os

algo_files = ['BubbleSort.py', 'InsertionSort.py', 'QuickSortMem.py', 'MergeSortMem.py', 'RadixSort.py', 'ShellSort.py']

def run_tests(samples = 10):
    prefix, postfix = "mprof run -T 0.01 -o "," ./PythonAlgorithms/"

    for i in range(0, samples):
        for algo in algo_files:
            i = 101
            algo_prefix = prefix+algo+".dat"+postfix+algo+" "
            print(algo_prefix)
            os.system(algo_prefix+str(i))
            print("\n\n")

if __name__ == '__main__':
    run_tests(samples = 1)