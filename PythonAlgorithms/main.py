import BubbleSort
import cProfile
import pstats
import random
import io
import argparse

def run_test():
    profiler = cProfile.Profile()
    profiler.enable()

    toSort = random.sample(range(0, 100000), 10000)
    BubbleSort.bubbleSort(toSort)

    profiler.disable()
    profiler.dump_stats("bubbleSort_py.stats")

    stats = pstats.Stats("bubbleSort_py.stats")
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

def main():
    parser_args = argparse.ArgumentParser(description="Get profilers for programs")
    parser_args.add_argument('Algorithm', metavar='algo', type=str, help="Enter sorting algorith")

    args = parser_args.parse_args()
    algo = args.Algorithm.lower()

    if algo == 'bubblesort':
        import BubbleSort
        sorter = BubbleSort.bubbleSort
    elif algo == 'insertionsort':
        import InsertionSort
        sorter = InsertionSort.insertionSort
    elif algo == 'insertionsortmodified':
        import InsertionSort
        sorter = InsertionSort.insertionSortModified
    elif algo == 'radixsort':
        import RadixSort
        sorter = RadixSort.radix
    elif algo == 'shellsort':
        import ShellSort
        sorter = ShellSort.shellSort
    elif algo == 'quicksort':
        pass

if __name__ == "__main__":
    main()