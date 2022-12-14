from math import log
import InsertionSort
import random
import cProfile
import pstats
import io
import sys
from memory_profiler import profile

@profile
def shellSort(lst: list) -> int:
    count = 0
    passes = int(log(len(lst))/log(2))
    while passes >= 1:
        increment = int(2 ** (passes - 1))
        for i in range(increment):
            count += InsertionSort.insertionSortModified(lst, i, increment)
        
        passes -= 1
    
    return count

def test_shellSort(count = 0, cprof = True):
    toSort =  random.sample(range(0, 100000), 10000)
    
    if cprof:
        profiler = cProfile.Profile()
        profiler.enable()

    
    shellSort(toSort)

    if cprof:
        profiler.disable()
        profiler.dump_stats("./PythonAlgorithms/outputs/shellSort/shellSort_py"+str(count)+".stats")

        stats = pstats.Stats("./PythonAlgorithms/outputs/shellSort/shellSort_py"+str(count)+".stats")
        stats.print_stats()

        # Copy to CSV
        result = io.StringIO()
        pstats.Stats(profiler,stream=result).print_stats()
        result=result.getvalue()
        # chop the string into a csv-like buffer
        result='ncalls'+result.split('ncalls')[-1]
        result='\n'.join([','.join(line.rstrip().split(None,5)) for line in result.split('\n')])

        # save it to disk
    
        with open('./PythonAlgorithms/outputs/shellSort/shellSort_py'+str(count)+'.csv', 'w+') as f:
            #f=open(result.rsplit('.')[0]+'.csv','w')
            f.write(result)
            f.close()


if __name__ == "__main__":
    if len(sys.argv) > 2:
        cprof = True
    else:
        cprof = False
    test_shellSort(int(sys.argv[1]), cprof)