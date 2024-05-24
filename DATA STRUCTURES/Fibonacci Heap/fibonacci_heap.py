from collections import deque
import math

class Node: 
    def __init__(self, key):
        self.key = key
        self.parent = self.child = self.left = self.right = None
        self.degree = 0
        self.mark = False

class FibonacciHeap:
    def __init__(self):
        self.total_nodes = 0
        self.root_list = None
        self.min_node = None
    
    def is_empty(self):
        return self.total_nodes == 0
    
    def size(self):
        return self.total_nodes 
    
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
    
    def get_min(self):
        if self.min_node is None:
            return None
        return self.min_node.key
    
    # delete minimum node
    def extract_min(self):
        z = self.min_node
        if z is not None:
            if z.child is not None:
                children = [x for x in self.iterate(z.child)]
                for i in range(len(children)):
                    children[i].parent = None
                    self.merge_with_root_list(children[i])
            self.remove_from_root_list(z)
            if z == z.right:
                self.min_node = self.root_list = None
            else:
                self.min_node = z.right
                self.consolidate()
                
            self.total_nodes -= 1
        return z
    
    def insert(self, key):
        new_node = Node(key)
        # make circle
        new_node.left = new_node.right = new_node
        self.merge_with_root_list(new_node)
        if self.min_node is None or self.min_node.key > new_node.key:
            self.min_node = new_node
        self.total_nodes += 1   
        return new_node
    
    def decrease_key(self, x, k):
        if x.key < k:
            print("error: new key is greater than current key")
            return None
        x.key = k
        y = x.parent
        if y is not None and x.key < y.key:
            self.cut(x, y)
            self.cascading_cut(y)
        # reset min node if necessary
        if x.key < self.min_node.key:
            self.min_node = x
    
    def cut(self, x, y):
        self.remove_from_child_list(y, x)
        y.degree -= 1
        self.merge_with_root_list(x)
        x.parent = None
        x.mark = False
    
    def cascading_cut(self, y):
        z = y.parent
        if z is not None:
            if y.mark is False:
                y.mark = True
            else:
                self.cut(y, z)
                self.cascading_cut(z)
    
    def merge(self, h2):
        last = h2.root_list.left
        h2.root_list.left = self.root_list.left
        self.root_list.left.right = h2.root_list
        self.root_list.left = last
        self.root_list.left.right = self.root_list
        
        if h2.min_node.key < self.min_node.key:
            self.min_node = h2.min_node
        self.total_nodes += h2.total_nodes
    
    # rebuild fibonacci heap
    def consolidate(self):
        A = [None] * int(math.log(self.total_nodes) * 2)
        nodes = [node for node in self.iterate(self.root_list)]
        for i in range(0, len(nodes)):
            x = nodes[i]
            deg = x.degree
            while A[deg] != None:
                y = A[deg]
                if x.key > y.key:
                    temp = x
                    x, y = y, temp
                self.heap_link(y, x)
                A[deg] = None
                deg += 1
            A[deg] = x
        
        # find new min node
        for i in range(0, len(A)):
            if A[i] is not None:
                if A[i].key < self.min_node.key:
                    self.min_node = A[i]
    
    # Set link y -> x
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
            node.right = self.root_list
            node.left = self.root_list.left
            self.root_list.left.right = node
            self.root_list.left = node
    
    # merge node to parent
    def merge_with_child_list(self, parent, node):
        if parent.child is None:
            parent.child = node
        else:
            node.right = parent.child.right
            node.left = parent.child
            parent.child.right.left = node
            parent.child.right = node
    
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

    # hacky way of printing the tree
    def print_fibonacci_heap(self, print_marked = False):
        unvisited = deque()
        root_list = []
        marked_nodes = []

        if self.root_list:
            for node in self.iterate(self.root_list):
                root_list.append(node.key)
                unvisited.append(node)

        print('--------------------')
        print('-- Fibonacci Heap --')
        print('--------------------')
        print(f'Total nodes: {self.total_nodes}')
        print(f'Minimum: {self.min_node.key if self.min_node else None}')
        print(f'Root list node: {self.root_list.key}')
        print(f'Root list: {root_list}')

        while unvisited:
            node = unvisited.popleft()
            if node.mark and (node.key not in marked_nodes):
                marked_nodes.append(node.key)
            if node.child:
                children = []
                for child in self.iterate(node.child):
                    children.append(child.key)
                    if child.child:
                        unvisited.append(child)
                    if child.mark and (child.key not in marked_nodes):
                        marked_nodes.append(child.key)
                print(f'Children of {node.key}: {children}')
        if print_marked:
            print(f'Marked nodes: {marked_nodes}')
        print('--------------------\n')