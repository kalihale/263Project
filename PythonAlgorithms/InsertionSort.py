import random
import cProfile
import pstats
import io
import sys
from memory_profiler import profile


def insertionSort(lst):
    count = 0
    n = len(lst)
    for i in range(1, n):

        newElement = lst[i]
        location = i - 1
        count += 1
        while location >= 0 and lst[location] > newElement:
            lst[location + 1] = lst[location]
            location -= 1
            count += 1
        lst[location + 1] = newElement
    
    return count

def insertionSortModified(lst, start, increment):
    count = 0
    n = len(lst)

    for j in range(start+increment, n, increment):
        newElement = lst[j]
        location = j - increment
        count += 1

        while location >= 0 and lst[location] > newElement and location + increment < len(lst):
            lst[location + increment] = lst[increment]
            location -= increment
            count += 1
        
        lst[location + increment] = newElement
    
    return count

def test_insertionSort(count = 0):
    toSort =  random.sample(range(0, 100000), 10000)
    profiler = cProfile.Profile()
    profiler.enable()

    
    insertionSort(toSort)

    profiler.disable()
    profiler.dump_stats("./PythonAlgorithms/outputs/insertionSort/insertionSort_py"+str(count)+".stats")

    stats = pstats.Stats("./PythonAlgorithms/outputs/insertionSort/insertionSort_py"+str(count)+".stats")
    stats.print_stats()

    # Copy to CSV
    result = io.StringIO()
    pstats.Stats(profiler,stream=result).print_stats()
    result=result.getvalue()
    # chop the string into a csv-like buffer
    result='ncalls'+result.split('ncalls')[-1]
    result='\n'.join([','.join(line.rstrip().split(None,5)) for line in result.split('\n')])

    # save it to disk
 
    with open("./PythonAlgorithms/outputs/insertionSort/insertionSort_py"+str(count)+".csv", 'w+') as f:
        #f=open(result.rsplit('.')[0]+'.csv','w')
        f.write(result)
        f.close()

if __name__ == "__main__":
    test_insertionSort(int(sys.argv[1]))
