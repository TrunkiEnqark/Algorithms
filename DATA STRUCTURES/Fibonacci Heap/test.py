from fibonacci_heap import FibonacciHeap
from fibonacci_heap import Node

fheap = FibonacciHeap()
fheap.insert(3)
fheap.insert(1)
fheap.insert(5)
fheap.insert(1000)
# print(fheap.extract_min())
# print(fheap.extract_min())
h2 = FibonacciHeap()
h2.insert(4)
h2.insert(10)
h2.insert(15)
h2.insert(16)
h2.insert(20)
h2.extract_min()
fheap.merge(h2)
fheap.print_fibonacci_heap()