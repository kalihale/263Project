
class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.next = None
    def __repr__(self):
        return self.data

class LinkedList:
    def __init__(self) -> None:
        self.head = None
        self.count = 0
    """ def __repr__(self):
        node = self.head
        nodes = []
        while node is not None:
            nodes.append(node.data)
            node = node.next
        nodes.append("None")
        return " -> ".join(nodes) """
    
    def __iter__(self):
        currentNode = self.head
        while currentNode is not None:
            yield currentNode.data
            currentNode = currentNode.next
    
    def add_node(self, node):
        node.next = self.head
        self.head = node
        self.count += 1
    
    def add(self, data):
        self.add_node(Node(data))

    def __getitem__(self, key):
        if key < 0 or key > self.count - 1:
            raise Exception('Index out of bounds')
        else:
            currentNode = self.head
            for i in range(key):
                currentNode = currentNode.next

            return currentNode.data

    def add_end_node(self, node):
        if self.head is None:
            self.head = node
        else:
            for currentNode in self:
                pass
            currentNode.next = node
        self.count += 1
    
    def __len__(self):
        return self.count
    
    def remove(self):
        if self.head is None or self.count == 0:
            raise Exception("Empty list")
        
        removed = self.head.data
        self.head = self.head.next
        self.count -= 1
        return removed
    
    def pop(self, index):
        return self.remove()
    
    def __str__(self):
        return self.count