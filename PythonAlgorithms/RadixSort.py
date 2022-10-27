

class CombineBuckets:
    def __init__(self) -> None:
        self.lst = None
        self.buckets = None
    
    def CombineBuckets(self, lst, buckets):
        self.lst = lst
        self.buckets = buckets
        j = 0
        for bucket in buckets:
            while bucket:
                self.list[j] = buckets.pop(0)
                j += 1
        return self.list

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
