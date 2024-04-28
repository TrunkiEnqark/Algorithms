from manager import Manage
from ui.menu import choose_option

MAIN_MENU = "FIBONACCI HEAP TEST"

MAIN_MENU_OPTIONS = [
    "Make a new Fibonacci Heap",
    "Edit a Fibonacci Heap",
    "Show list of Fibonacci Heaps",
    "Union two Fibonacci Heaps",
    "Quit"
]

FIBHEAP_OPTIONS = [
    "Get minimum",
    "Extract minimum",
    "Insert a new node",
    "Show this Fibonacci Heap",
    "Quit"
]

fheap_manager = Manage()
space = "========================================="

while True:
    print(space)
    print(MAIN_MENU)
    choosen = choose_option(MAIN_MENU_OPTIONS)
    match choosen:
        case 1:
            name = input("Enter name of Fibonacci Heap: ")
            fheap_manager.add(name)
        case 2:
            fheap_manager.show_lst()
            idx = 0
            while True:
                print(space)
                name = input("Enter name of Fibonacci Heap you want to edit: ")
                idx = fheap_manager.find(name)
                if idx == -1:
                    print("Error: Wrong name, press again")
                else:
                    break
            while True:
                print(space)
                edit_choosen = choose_option(FIBHEAP_OPTIONS)
                name = fheap_manager.lst[idx].name
                match edit_choosen:
                    # get minimum
                    case 1:
                        fibheap = fheap_manager.get_fib_heap(name)
                        print(f'Minimum of "{name}" is: {fibheap.get_min()}')
                    # Extract minimum
                    case 2:
                        fheap_manager.lst[idx].fib_heap.extract_min()
                        print("Minimum node of Fibonacci Heap has been deleted!")
                    # insert a new node
                    case 3:
                        new_key = int(input("Enter key of node you want to insert: "))
                        fheap_manager.lst[idx].fib_heap.insert(new_key)
                        print(f"Node {new_key} has been inserted!")
                    # Show
                    case 4:
                        fheap_manager.lst[idx].fib_heap.print_fibonacci_heap()
                    case 5:
                        break
        case 3:
            fheap_manager.show_lst()
        case 4:
            fheap_manager.show_lst()
            print("Enter 2 names of Fibonacci Heap you want to merge: ")
            fib1 = input()
            while not fheap_manager.in_list(fib1):
                print("This name is not in list, please enter the RIGHT NAME")
                fib1 = input()
            print(f'Fibonacci Heap named {fib1}... OK!')
            fib2 = input()
            while not fheap_manager.in_list(fib2):
                print("This name is not in list, please enter the RIGHT NAME")
                fib2 = input()
            print(f'Fibonacci Heap named {fib2}... OK!')
            fib_merge = input("Enter the new name: ")
            fheap1 = fheap_manager.get_fib_heap(fib1)
            fheap2 = fheap_manager.get_fib_heap(fib2)
    
            FibHeap = fheap1
            FibHeap.merge(fheap2)
            fheap_manager.add(fib_merge, FibHeap)
            
            print(f'Both of them has been merged!')
        case 5:
            break
        case _:
            raise RuntimeError("Unknown error")