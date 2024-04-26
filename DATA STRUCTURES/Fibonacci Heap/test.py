from fibonacci_heap import FibonacciHeap
from fibonacci_heap import Node

fheap = FibonacciHeap()
fheap.insert(5)
fheap.insert(10)
fheap.insert(14)
fheap.insert(12)
fheap.insert(2)
fheap.decrease_key(Node(12), 6)

fheap.print_fibonacci_heap()