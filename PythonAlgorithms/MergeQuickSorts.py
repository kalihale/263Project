import random
import cProfile
import pstats
import io
import sys
from memory_profiler import profile


def mergeSortStart(lst):
    return mergeSort(lst, 0, len(lst) - 1)

@profile
def mergeSort(lst, first, last):
    middle = 0
    count = 0
    if first < last:
        middle = (first + last)//2
        count += mergeSort(lst, first, middle)
        count += mergeSort(lst, middle+1, last)
        count += mergeLists(lst, first, middle, middle+1, last)
    return count


def mergeLists(lst, start1, end1, start2, end2):
    count = 0
    result = [None] * len(lst)
    finalStart = start1
    finalEnd = end2
    indexC = 0
    while start1 <= end1 and start2 <= end2:
        count += 1
        if lst[start1] < lst[start2]:
            result[indexC] = lst[start1]
            start1 += 1
        else:
            result[indexC] = lst[start2]
            start2 += 1
        
        indexC += 1
    
    if start1 <= end1:
        for i in range(start1, end1+1):
            result[indexC] = lst[i]
            indexC += 1
    else:
       for i in range(start2, end2+1):
            result[indexC] = lst[i]
            indexC += 1 
    
    indexC = 0
    for i in range(finalStart, finalEnd+1):
        lst[i] = result[indexC]
        indexC += 1
    
    return count

def pivotArr(pivot, arr, left, right, comparisons):
    temp = arr[right]
    arr[right]= arr[pivot]
    arr[pivot] = temp
    i = left
    for j in range(i, right):
            comparisons[0] += 1
            if arr[j] < arr[right]:
                temp = arr[i]
                arr[i] = arr[j]
                arr[j] = temp
                i += 1
    
    temp = arr[i]
    arr[i] = arr[right]
    arr[right] = temp
    return i

@profile
def quickSortPivotFirst(lst, first, last, comparisons):
    count = 0
    pivot = 0
    if first < last:
        pivot = pivotArr(first, lst, first, last, comparisons)
        quickSortPivotFirst(lst, first, pivot - 1, comparisons)
        quickSortPivotFirst(lst, pivot + 1, last, comparisons)
    return count

def quickSortPivotLast(lst, first, last, comparisons):
    count = 0
    pivot = 0
    if first < last:
        pivot = pivotArr(last, lst, first, last, comparisons)
        quickSortPivotLast(lst, first, pivot - 1, comparisons)
        quickSortPivotLast(lst, pivot + 1, last, comparisons)
    return count

def quickSortPivotRandom(lst, first, last, comparisons):
    count = 0
    pivot = 0
    if first < last:
        pivot = pivotArr(random.randint(first, last), lst, first, last, comparisons)
        quickSortPivotRandom(lst, first, pivot - 1, comparisons)
        quickSortPivotRandom(lst, pivot + 1, last, comparisons)
    return count


# Tests:


def test_quickSort(count = 0):
    toSort = random.sample(range(0, 100000), 10000)
    comparisons = [0]
    
    profiler = cProfile.Profile()
    profiler.enable()

    quickSortPivotFirst(toSort, 0, len(toSort) - 1, comparisons)

    profiler.disable()
    profiler.dump_stats("./PythonAlgorithms/outputs/quickSort/quickSort_py"+str(count)+".stats")

    # Copy to CSV
    result = io.StringIO()
    pstats.Stats(profiler,stream=result).print_stats()
    result=result.getvalue()
    # chop the string into a csv-like buffer
    result='ncalls'+result.split('ncalls')[-1]
    result='\n'.join([','.join(line.rstrip().split(None,5)) for line in result.split('\n')])

    # save it to disk
 
    with open("./PythonAlgorithms/outputs/quickSort/quickSort_py"+str(count)+".csv", 'w+') as f:
        #f=open(result.rsplit('.')[0]+'.csv','w')
        f.write(result)
        f.close()

def test_mergeSort(count = 0):
    toSort = random.sample(range(0, 100000), 10000)

    profiler = cProfile.Profile()
    profiler.enable()

    mergeSort(toSort, first = 0, last = len(toSort) - 1)

    profiler.disable()
    profiler.dump_stats("./PythonAlgorithms/outputs/mergeSort/mergeSort_py"+str(count)+".stats")

    # Copy to CSV
    result = io.StringIO()
    pstats.Stats(profiler,stream=result).print_stats()
    result=result.getvalue()
    # chop the string into a csv-like buffer
    result='ncalls'+result.split('ncalls')[-1]
    result='\n'.join([','.join(line.rstrip().split(None,5)) for line in result.split('\n')])

    # save it to disk

    with open('./PythonAlgorithms/outputs/mergeSort/mergeSort_py'+str(count)+'.csv', 'w+') as f:
        #f=open(result.rsplit('.')[0]+'.csv','w')
        f.write(result)
        f.close()

def main(count = 0):
    test_mergeSort(count)
    test_quickSort(count)

if __name__ == "__main__":
    main(int(sys.argv[1]))
