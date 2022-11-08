import BubbleSort
import cProfile
import pstats
import random

def main():
    profiler = cProfile.Profile()
    profiler.enable()

    toSort = random.sample(range(0, 100000), 10000)
    BubbleSort.bubbleSort(toSort)

    profiler.disable()
    profiler.dump_stats("bubbleSort_py.stats")

    stats = pstats.Stats("bubbleSort_py.stats")
    stats.print_stats()


if __name__ == "__main__":
    main()