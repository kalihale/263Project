
class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.next = None
    def __repr__(self):
        return self.data

class LinkedList:
    def __init__(self) -> None:
        self.head = None
    def __repr__(self):
        node = self.head
        nodes = []
        while node is not None:
            nodes.append(node.data)
            node = node.next
        nodes.append("None")
        return " -> ".join(nodes)
    
    def __iter__(self):
        currentNode = self.head
        while currentNode is not None:
            yield currentNode
            currentNode = currentNode.next
    
    def add_node(self, node):
        node.next = self.head
        self.head = node
    
    def add(self, data):
        self.add_node(Node(data))

    def __getitem__(self, key):
        if key < 0 or key >= self.__len__():
            raise Exception('Index out of bounds')
        else:
            index = 0
            for currentNode in self:
                if index == key:
                    return currentNode.data
                index += 1
            return None

    def add_end_node(self, node):
        if self.head is None:
            self.head = node
        else:
            for currentNode in self:
                pass
            currentNode.next = node
    
    def __len__(self):
        size = 0
        for currentNode in self:
            size += 1
        return size
    
    def remove(self):
        if self.head is None:
            raise Exception("Empty list")
        
        removed = self.head.data
        self.head = self.head.next
        return removed
    
    def pop(self, index):
        return self.remove()