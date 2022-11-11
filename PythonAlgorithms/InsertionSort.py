import random
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

if __name__ == "__main__":
    test_lst = random.sample(range(0, 100000), 10000)
    print(insertionSort(test_lst))
