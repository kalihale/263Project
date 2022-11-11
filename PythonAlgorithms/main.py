import BubbleSort
import RadixSort
import cProfile
import pstats
import random
import io
import argparse

def convert_stats_to_csv(profiler:cProfile.Profile, csv_name:str):
    # Copy to CSV
    result = io.StringIO()
    pstats.Stats(profiler,stream=result).print_stats()
    result=result.getvalue()
    # chop the string into a csv-like buffer
    result='ncalls'+result.split('ncalls')[-1]
    result='\n'.join([','.join(line.rstrip().split(None,5)) for line in result.split('\n')])

    # save it to disk
 
    with open(csv_name, 'w+') as f:
        #f=open(result.rsplit('.')[0]+'.csv','w')
        f.write(result)
        f.close()

def run_test():
    profiler = cProfile.Profile()
    profiler.enable()

    toSort = [1405, 975, 23, 9803, 4835, 2082, 7368, 573, 804, 746, 4703, 1421, 4273, 1208, 521, 2050]#random.sample(range(0, 100000), 10000)
    RadixSort.radixLL(toSort, 4)

    profiler.disable()
    profiler.dump_stats("radixSort_py.stats")

    stats = pstats.Stats("radixSort_py.stats")
    stats.print_stats()

    # Copy to CSV
    result = io.StringIO()
    pstats.Stats(profiler,stream=result).print_stats()
    result=result.getvalue()
    # chop the string into a csv-like buffer
    result='ncalls'+result.split('ncalls')[-1]
    result='\n'.join([','.join(line.rstrip().split(None,5)) for line in result.split('\n')])

    # save it to disk
 
    with open('./PythonAlgorithms/radixSort_py.csv', 'w+') as f:
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
    #main()
    run_test()