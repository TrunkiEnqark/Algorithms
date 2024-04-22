import math

class FibonacciHeap:
    class Node: 
        def __init__(self, key, value) -> None:
            self.key = key
            self.value = value
            self.parent = self.child = self.left = self.right = None
            self.degree = 0
            self.mark = False
    
    def iterate(self, head):
        node = stop = head
        flag = False
        while True:
            if node == stop and flag is True:
                break
            elif node == stop:
                flag = True
            yield node
            node = node.right
    
    root_list, min_node = None, None
    
    total_nodes = 0
    
    def get_min(self):
        return self.min_node
    