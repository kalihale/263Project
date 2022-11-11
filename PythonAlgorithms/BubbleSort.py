import random
import cProfile
import pstats
import io

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

def test_bubbleSort():
    toSort =  random.sample(range(0, 100000), 10000)
    profiler = cProfile.Profile()
    profiler.enable()

    
    bubbleSort(toSort)

    profiler.disable()
    profiler.dump_stats("./PythonAlgorithms/bubbleSort_py.stats")

    stats = pstats.Stats("./PythonAlgorithms/bubbleSort_py.stats")
    stats.print_stats()

    # Copy to CSV
    result = io.StringIO()
    pstats.Stats(profiler,stream=result).print_stats()
    result=result.getvalue()
    # chop the string into a csv-like buffer
    result='ncalls'+result.split('ncalls')[-1]
    result='\n'.join([','.join(line.rstrip().split(None,5)) for line in result.split('\n')])

    # save it to disk
 
    with open('./PythonAlgorithms/bubbleSort_py.csv', 'w+') as f:
        #f=open(result.rsplit('.')[0]+'.csv','w')
        f.write(result)
        f.close()

if __name__ == "__main__":
    test_bubbleSort()
