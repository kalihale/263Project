import os

algo_files = ['BubbleSort.py', 'InsertionSort.py', 'QuickSortMem.py', 'MergeSortMem.py', 'RadixSort.py', 'ShellSort.py']

def run_tests():
    prefix, postfix = "mprof run -T 0.01 -o "," ./PythonAlgorithms/"
    mem_outputs = postfix +"outputs/MemoryOutputs/"

    for algo in algo_files:
        i = 12000
        algo_prefix = prefix+mem_outputs+algo+".dat"+postfix+algo+" "
        print(algo_prefix)
        os.system(algo_prefix+str(i))
        print("\n\n")

if __name__ == '__main__':
    run_tests()