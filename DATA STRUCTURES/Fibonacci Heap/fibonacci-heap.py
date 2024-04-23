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
    
    # delete minimum node
    def extract_min(self):
        z = self.min_node
        if z is not None:
            if z is not None:
                children = [x for x in self.iterate(z.child)]
                for i in range(len(children)):
                    self.merge_with_root_list(children[i])
                    children[i].parent = None
            self.remove_from_root_list(z)
            
            if z == z.right:
                self.min_node = self.root_list = None
        