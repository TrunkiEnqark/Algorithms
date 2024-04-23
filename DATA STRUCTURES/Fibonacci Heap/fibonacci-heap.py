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
            else:
                self.min_node = z.right
                self.consolidate()
                
            self.total_nodes -= 1
        return z
    
    # rebuild fibonacci heap
    def consolidate(self):
        A = [None] * int(math.log(self.total_nodes) * 2)
        nodes = [node for node in self.iterate(self.root_list)]
        for i in range(len(nodes)):
            x = nodes[i]
            deg = x.degree
            while A[deg] != None:
                y = A[deg]
                if x.key > y.key:
                    x, y = y, x
                self.heap_link(y, x)
                A[deg] = None
                deg += 1
            A[deg] = x
        
        # find new min node
        for i in range(len(A)):
            if A[i] is not None:
                if A[i].key < self.min_node.key:
                    self.min_node = A[i]
    
    # Set link x -> y
    # Of course, y.key < x.key
    def heap_link(self, y, x):
        self.remove_from_root_list(y)
        y.left = y.right = y
        # merge y to x
        self.merge_with_child_list(x, y)
        x.degree += 1
        y.parent = x
        y.mark = False
    
    # merge node to root list
    def merge_with_root_list(self, node):
        if self.root_list is None:
            self.root_list = node
        else:
            node.right = self.root_list.right
            node.left = self.root_list
            self.root_list.right.left = node
            self.root_list.left = node
    
    # merge node to parent
    def merge_with_child_list(self, parent, node):
        if parent.child is None:
            parent.child = node
        else:
            node.right = parent.child.right
            node.left = parent.child
            parent.child.right.left = node
            parent.child.left = node
    
    # remove node from root list
    def remove_from_root_list(self, node):
        if node == self.root_list:
            self.root_list = node.right
        node.left.right = node.right
        node.right.left = node.left
    
    # remove node from parent
    def remove_from_child_list(self, parent, node):
        if parent.child == parent.child.right:
            parent.child = None
        elif parent.child == node:
            parent.child = node.right
            node.right.parent = parent
        node.left.right = node.right
        node.right.left = node.left