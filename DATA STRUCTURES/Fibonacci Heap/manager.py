from fibonacci_heap import FibonacciHeap

class Item():
    def __init__(self, _name, _fheap = FibonacciHeap()):
        self.name = _name
        self.fib_heap = _fheap
    
    def show(self):
        print(f"Name: {self.name} [")
        self.fib_heap.show()
        print(f']')

class Manage:
    def __init__(self):
        self.lst = []
    
    def add(self, name, fheap = FibonacciHeap()):
        self.lst.append(Item(name, fheap))
    
    def show_lst(self):
        for item in self.lst:
            item.show()
    
    def find(self, name):
        for i in range(len(self.lst)):
            if self.lst[i].name == name:
                return i
        return -1

    def get_fib_heap(self, name):
        for item in self.lst:
            if item.name == name:
                return item.fib_heap
        return "Not found!"
    
    def in_list(self, name):
        if self.find(name) == -1:
            return False
        return True