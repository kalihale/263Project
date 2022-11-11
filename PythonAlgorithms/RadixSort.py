from LinkedList import *
import cProfile
import pstats
import io


class CombineBuckets:
    def __init__(self) -> None:
        self.lst = None
        self.buckets = None
    
    def CombineBuckets(self, lst, buckets):
        self.lst = lst
        self.buckets = buckets
        j = 0
        for bucket in self.buckets:
            while bucket:
                self.lst[j] = bucket.pop(0)
                j += 1
        return self.lst

def radix(lst, keySize):
    bucket_length = 10
    buckets = []
    gcb = CombineBuckets()

    for i in range(bucket_length):
        buckets.append([])
    
    shift = 1

    for i in range(1, keySize):
        for j in range(len(lst)):
            buckets[ (lst[j] // shift) % 10].append(lst[j])
        
        lst = gcb.CombineBuckets(lst, buckets)
        shift *= 10
    
    return lst

def radixLL(lst, keySize):
    bucket_length = 10
    buckets = LinkedList()
    gcb = CombineBuckets()

    for i in range(bucket_length):
        toAdd = LinkedList()
        buckets.add(toAdd)
    
    shift = 1

    for i in range(1, keySize):
        for j in range(len(lst)):
            buckets[ (lst[j] // shift) % 10].add(lst[j])
        
        lst = gcb.CombineBuckets(lst, buckets)
        shift *= 10
    
    return lst

def testRadixSort():
    profiler = cProfile.Profile()
    profiler.enable()

    toSort = [1405, 975, 23, 9803, 4835, 2082, 7368, 573, 804, 746, 4703, 1421, 4273, 1208, 521, 2050]#random.sample(range(0, 100000), 10000)
    radixLL(toSort, 4)

    profiler.disable()
    profiler.dump_stats("./PythonAlgorithms/radixSort_py.stats")

    stats = pstats.Stats("./PythonAlgorithms/radixSort_py.stats")
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


if __name__ == "__main__":
    testRadixSort()
