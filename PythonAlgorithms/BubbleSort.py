
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