import random
import cProfile
import pstats
import io
import sys
from memory_profiler import profile

@profile
def bubbleSort(lst):
    count = 0
    numberOfPairs = len(lst)
    swappedElements = True
    while swappedElements:
        numberOfPairs -= 1
        swappedElements = False
        for i in range(numberOfPairs):
            count += 1

            if lst[i] > lst[i+1]:
                lst[i], lst[i+1] = lst[i+1], lst[i]
                swappedElements = True
    
    return lst

def test_bubbleSort(count=0):
    toSort =  random.sample(range(0, 100000), 10000)
    profiler = cProfile.Profile()
    profiler.enable()

    
    bubbleSort(toSort)

    profiler.disable()
    profiler.dump_stats("./PythonAlgorithms/outputs/bubbleSort/bubbleSort_py"+str(count)+".stats")

    stats = pstats.Stats("./PythonAlgorithms/outputs/bubbleSort/bubbleSort_py"+str(count)+".stats")
    stats.print_stats()

    # Copy to CSV
    result = io.StringIO()
    pstats.Stats(profiler,stream=result).print_stats()
    result=result.getvalue()
    # chop the string into a csv-like buffer
    result='ncalls'+result.split('ncalls')[-1]
    result='\n'.join([','.join(line.rstrip().split(None,5)) for line in result.split('\n')])

    # save it to disk
 
    with open('./PythonAlgorithms/outputs/bubbleSort/bubbleSort_py'+str(count)+'.csv', 'w+') as f:
        #f=open(result.rsplit('.')[0]+'.csv','w')
        f.write(result)
        f.close()

if __name__ == "__main__":
    test_bubbleSort(int(sys.argv[1]))
