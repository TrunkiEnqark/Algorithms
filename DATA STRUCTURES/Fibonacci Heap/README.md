# Fibonacci Heap

> Fibonacci heap (hay Fib heap) là một loại cấu trúc dữ liệu hàng đợi ưu tiên được thiết kế để hỗ trợ các hoạt động sau một cách hiệu quả:
> 1. Chèn phần tử (`insert`): Thời gian trung bình `O(1)`.
> 2. Xóa phần tử nhỏ nhất (`extract-min`): Thời gian trung bình `O(log n)`, với `n` là số lượng phần tử.
> 3. Giảm ưu tiên (`decrease-key`): Thời gian trung bình `O(1)` với phép toán này không có bất kỳ công việc `heap-ify` nào, điều này giúp nó trở nên nhanh hơn nhiều so với các loại heap khác.

![1](https://github.com/TrunkiEnqark/Algorithms/assets/89256879/0556acc5-6b06-4442-b7b3-03aa1338cffa)

# Table of Contents

<!-- vscode-markdown-toc -->
* [Structure of Fibonacci Heap](#StructureofFibonacciHeap)
* [Fibonacci Heap Methods](#FibonacciHeapMethods)
* [Time complexity comparison](#Timecomplexitycomparison)
* [Algorithms (pseudocode)](#Algorithmspseudocode)
	* [Creating a new Fibonacci heap](#CreatinganewFibonacciheap)
	* [Inserting a node](#Insertinganode)
	* [Finding a minimun node](#Findingaminimunnode)
	* [Uniting two Fibonacci heaps](#UnitingtwoFibonacciheaps)
	* [Ectracting the minimum node](#Ectractingtheminimumnode)
	* [Dereasing a key](#Dereasingakey)
	* [Deleting a node](#Deletinganode)
* [References](#References)

##  1. <a name='StructureofFibonacciHeap'></a>Structure of Fibonacci Heap
- `total_nodes`: Số lượng node trong heap
- `root_list`: Gốc của cây đầu tiên trong heap
- `min_node`: node chứa giá trị nhỏ nhất
- Trong `Node` gồm:
    - `key`: Giá trị của node
    - `parent`, `child`, `left`, `right`: Dùng để trỏ đến 4 hướng của node 
    - `degree`: Bậc của node
    - `mark`: Có bị mất một nút con kể từ lần cuối cùng nó trở thành nút con của một nút khác hay không

##  2. <a name='FibonacciHeapMethods'></a>Fibonacci Heap Methods
- `get_min()`: Lấy giá trị nhỏ nhất trong heaps
- `extract_min()`: Trả về giá trị nhỏ nhất hiện tại và xóa node này ra khỏi heaps
- `insert(key)`: Chèn thêm một `node` có giá trị `key` vào heaps
- `decrease_key(x, k)`: Giảm node `x` xuống giá trị `k`  
- `merge(h2)`: Hợp nhất cây `h2` vào `root_list`

##  3. <a name='Timecomplexitycomparison'></a>Time complexity comparison
|Operations          | Make Heap | Minimum  | Extract Min | Insert      | Decrease Key | Union    |
|:-------------------|:---------:|:--------:|:-----------:|:-----------:|:------------:|:--------:|
|**Binary heap**     |`O(1)`     |`O(1)`    |`O(log n)`   | `O(log n)`  |`O(log n)`    |`O(n)`    |  
|**Fibonacci heap**  |`O(1)`     |`O(1)`    |`O(log n)`   | `O(1)`      |`O(1)`        |`O(1)`    | 

##  4. <a name='Algorithmspseudocode'></a>Algorithms (pseudocode)

###  4.1. <a name='CreatinganewFibonacciheap'></a>Creating a new Fibonacci heap

```cpp
MAKE_HEAP()
1. H.min = NULL
2. H.total_nodes = 0
3. return H
```

###  4.2. <a name='Insertinganode'></a>Inserting a node

```cpp
INSERT(H, x)
1. degree[x] = 0
2. parent[x] = NULL
3. child[x] = NULL
4. left[x] = NULL
5. right[x] = NULL
6. mark[x] = FALSE
7. Add x to root list of H
8. if x.key < H.min_node.key then
9.      H.min_node = x
10. end if
11. H.total_nodes += 1
```

![insert](https://github.com/TrunkiEnqark/Algorithms/assets/89256879/909b75da-dc0d-4139-b732-028deca370b2)

###  4.3. <a name='Findingaminimunnode'></a>Finding a minimun node

```cpp
FIND_MIN(H)
1. return H.min_node
```

###  4.4. <a name='UnitingtwoFibonacciheaps'></a>Uniting two Fibonacci heaps

```cpp
UNION(H1, H2)
1. H = MAKE_HEAP()
2. H.min_node = H1.min_node
3. concatenate the root list of H2 with the root list of H
4. H.min_node = minimum(H1.min_node, H2.min_node)
5. H.total_nodes = H1.total_nodes + H2.total_nodes
8. return H
```

###  4.5. <a name='Ectractingtheminimumnode'></a>Ectracting the minimum node

```cpp
EXTRACT_MIN(H)
1. temp = H.min_node
2. if temp != NULL then
3.      add child of temp to root list of H
4.      remove temp from root list of H
5.      if temp == temp.right then
6.          H.min_node = NULL
7.      else 
8.          H.min_node = temp.right
9.          CONSOLIDATE(H)
10.     end if
11.     H.total_nodes -= 1
12. end if
13. return temp
```

```cpp
CONSOLIDATE(H)
1. let A[0..D(H.total_nodes)] be a new array
2. for i = 0 to D(H.total_nodes) do
3.      A[i] = NULL
4. end for
5. for each node w in root list of H do
6.      x = w
7.      d = x.degree
8.      while A[d] != NULL do
9.          y = A[d]
10.         if x.key > y.key then
11.             swap(x, y)
12.         end if
13.         HEAP_LINK(H, y, x)
14.         A[d] = NULL
15.         d += 1
16.     end while
17.     A[d] = x
18. end for
19. H.min_node = NULL
20. for i = 0 to D(H.total_nodes) do
21.     if A[i] != NULL then
22.         add A[i] to the root list of H
23.         if (H.min_node == NULL) or (H.min_node.key > A[i].key) then
24.             H.min_node = A[i]
25.         end if
26.     end if
27. end for
```

```cpp
HEAP_LINK(H, y, x)
1. remove y from the root list of H
2. make y a child of x, incrementing x.degree
3. y.mark = FALSE
```

![extract_min_a](https://github.com/TrunkiEnqark/Algorithms/assets/89256879/fac6242d-1c65-4eda-aef8-6bbe634a136f)
![extract_min_b](https://github.com/TrunkiEnqark/Algorithms/assets/89256879/51417e7e-d7fa-4b3c-b51d-18d3e8b9c140)

(a) Fibonacci heap H lúc đầu

(b) Nút 3 (nút nhỏ nhất) đã bị xóa

(c)-(m) Xây dựng lại H

###  4.6. <a name='Dereasingakey'></a>Dereasing a key

```cpp
DECREASE_KEY(H, x, k)
1. if k > x.key then
2.      error("new key is greater than current key")
3. end if
4. x.key = k
5. y = x.parent
6. if y != NULL and x.key < y.key then
7.      CUT(H, x, y)
8.      CASCADING_CUT(H, y)
9. end if
10. if x.key < H.min_node.key then
11.     H.min_node = x
12. end if
```

```cpp
CUT(H, x, y)
1. remove x from the child list of y, decrementing y.degree
2. add x to the root list of H
3. x.parent = NULL
4. x.mark = TRUE
```

```cpp
CASCADING_CUT(H, y)
1. z = y.parent
2. if z != NULL then
3.      if y.mark == FALSE then
4.          y.mark = TRUE
5.      else 
6.          CUT(H, y, z)
7.          CASCADING_CUT(H, z)
8.      end if
9. end if
```

![decrease key](https://github.com/TrunkiEnqark/Algorithms/assets/89256879/854a99ca-0050-484b-bc93-6a5ef140c3ab)

(a)-(b) `DECREASE_KEY(H, 46, 15)`

(c)-(e) `DECREASE_KEY(H, 35, 5)`

###  4.7. <a name='Deletinganode'></a>Deleting a node
```cpp
DELETE(H, x)
1. DECREASE_KEY(H, x, -infinity)
2. EXTRACT_MIN(H)
```

##  5. <a name='References'></a>References:

> [Intro to Algorithm book](http://staff.ustc.edu.cn/~csli/graduate/algorithms/book6/chap21.htm)

> [Wikipedia](https://en.wikipedia.org/wiki/Fibonacci_heap)

> [Daniel](https://github.com/danielborowski/fibonacci-heap-python)