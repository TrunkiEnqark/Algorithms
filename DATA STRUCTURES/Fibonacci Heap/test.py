from fibonacci_heap import FibonacciHeap
from random import randint

def make_heap():
    fib = FibonacciHeap()
    for i in range(100):
        fib.insert(randint(1, 100))
    return fib

if __name__ == '__main__':
    fib = make_heap()
    fib.print_fibonacci_heap()
    print(fib.extract_min().key)
    fib.print_fibonacci_heap()
    print(fib.extract_min().key)