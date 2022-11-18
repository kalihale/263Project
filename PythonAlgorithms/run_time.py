import os

algo_files = ['BubbleSort.py', 'InsertionSort.py', 'MergeQuickSort.py', 'RadixSort.py', 'ShellSort.py']

def run_tests(samples = 10):
    prefix = "python ./PythonAlgorithms/"

    for i in range(0, samples):
        for algo in algo_files:
            algo_prefix = prefix+algo+" "
            os.system(algo_prefix+str(i))

if __name__ == '__main__':
    run_tests(samples = 100)