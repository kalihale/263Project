from math import log
import InsertionSort
def ShellSort(lst: list) -> int:
    count = 0
    passes = int(log(len(lst))/log(2))
    while passes >= 1:
        increment = int(2 ** (passes - 1))
        for i in range(increment):
            count += InsertionSort.insertionSortModified(lst, i, increment)
        
        passes -= 1
    
    return count