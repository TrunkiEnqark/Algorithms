
# Fibonacci Heap

Fibonacci Heap được phát triển bởi Michael L.Fredman và Robert E.Tarjan vào năm 
1984 và lần đầu tiên được công bố trong một tạp chí khoa học vào năm 1987. Tên của 
Fibonacci heap xuất phát từ dãy số Fibonacci được sử dụng trong phân tích thời gian 
chạy.
Đống Fibonacci là một cấu trúc dữ liệu đống bao gồm một bộ sưu tập các cây. Vì vậy, 
nó cũng được ghép vào cấu trúc cây. Thời gian thực hiện giải thuật của nó hơn rất nhiều 
của một đống nhị thức (Binary Heap).

![1](https://github.com/TrunkiEnqark/Algorithms/assets/89256879/0556acc5-6b06-4442-b7b3-03aa1338cffa)

# Mục lục

<!-- vscode-markdown-toc -->
1. [Cấu trúc của Fibonacci Heap](#CutrccaFibonacciHeap)
2. [Các phép xử lý](#Ccphpxl)
3. [So sánh độ phức tạp thời gian giữa Fibonacci Heap và Binary Heap](#SosnhphctpthigiangiaFibonacciHeapvBinaryHeap)
4. [Hàm tiềm năng (Potential Function)](#HmtimnngPotentialFunction)
5. [Bậc tối đa (Maximum Degree)](#BctiaMaximumDegree)
6. [Thuật toán và mã giả (pseudocode)](#Thuttonvmgipseudocode)
	* 6.1. [Khởi tạo một Fibonacci Heap](#KhitomtFibonacciHeap)
	* 6.2. [Chèn một node mới vào (Insert)](#ChnmtnodemivoInsert)
	* 6.3. [Tìm node nhỏ nhất (Find min)](#TmnodenhnhtFindmin)
	* 6.4. [Hợp nhất 2 Fibonacci Heap (Union)](#Hpnht2FibonacciHeapUnion)
	* 6.5. [Trích xuất node nhỏ nhất (Extract min)](#TrchxutnodenhnhtExtractmin)
	* 6.6. [Giảm giá trị của một node (Decrease Key)](#GimgitrcamtnodeDecreaseKey)
	* 6.7. [Xóa một node (Delete)](#XamtnodeDelete)
7. [References](#References)


##  1. <a name='CutrccaFibonacciHeap'></a>Cấu trúc của Fibonacci Heap
- `total_nodes`: Số lượng node trong heap
- `root_list`: Gốc của cây đầu tiên trong heap
- `min_node`: node chứa giá trị nhỏ nhất
- Trong `Node` gồm:
    - `key`: Giá trị của node
    - `parent`, `child`, `left`, `right`: Dùng để trỏ đến 4 hướng của node 
    - `degree`: Bậc của node
    - `mark`: Có bị mất một nút con kể từ lần cuối cùng nó trở thành nút con của một nút khác hay không

##  2. <a name='Ccphpxl'></a>Các phép xử lý
- `get_min()`: Lấy giá trị nhỏ nhất trong heaps
- `extract_min()`: Trả về giá trị nhỏ nhất hiện tại và xóa node này ra khỏi heaps
- `insert(key)`: Chèn thêm một `node` có giá trị `key` vào heaps
- `decrease_key(x, k)`: Giảm node `x` xuống giá trị `k`  
- `merge(h2)`: Hợp nhất cây `h2` vào `root_list`

##  3. <a name='SosnhphctpthigiangiaFibonacciHeapvBinaryHeap'></a>So sánh độ phức tạp thời gian giữa Fibonacci Heap và Binary Heap
|Operations          | Make Heap | Minimum  | Extract Min | Insert      | Decrease Key | Union    |
|:-------------------|:---------:|:--------:|:-----------:|:-----------:|:------------:|:--------:|
|**Binary heap**     |`O(1)`     |`O(1)`    |`O(log n)`   | `O(log n)`  |`O(log n)`    |`O(n)`    |  
|**Fibonacci heap**  |`O(1)`     |`O(1)`    |`O(log n)`   | `O(1)`      |`O(1)`        |`O(1)`    | 

##  4. <a name='HmtimnngPotentialFunction'></a>Hàm tiềm năng (Potential Function)

Hàm tiềm năng (potential function) được sử dụng trong phân tích chi phí khấu hao (amortized analysis) cho các thao tác trên Fibonacci Heap:
Cho một Fibonacci Heap H, ta định nghĩa:
- `t(H)` là số lượng cây trong danh sách gốc của H
- `m(H)` là số lượng nút đã đánh dấu trong H

Hàm tiềm năng Φ(H) của Fibonacci Heap H được định nghĩa như sau:
`Φ(H) = t(H) + 2m(H)`
Ví dụ, nếu H có 5 cây trong danh sách gốc và 3 nút đánh dấu (ảnh trên), thì `Φ(H) = 5 + 2*3 = 11`.

##  5. <a name='BctiaMaximumDegree'></a>Bậc tối đa (Maximum Degree)

Xuyên suốt bài phần README này đề cập đến giá trị `D(n)` là bậc tối đa của một node bất kỳ trong Fibonacci Heap. Giá trị `D(n)` này được giới hạn bởi `log(n)`.

##  6. <a name='Thuttonvmgipseudocode'></a>Thuật toán và mã giả (pseudocode)

###  6.1. <a name='KhitomtFibonacciHeap'></a>Khởi tạo một Fibonacci Heap

Để tạo một Fibonacci heap rỗng, thủ tục MAKE_HEAP cấp phát và trả về đối tượng Fibonacci heap H, trong đó H.total_nodes = 0, H.min_node = NULL, H.root_list = NULL; không có cây nào trong H. Bởi vì `t(H) = 0` và `m(H) = 0`, tiềm năng của Fibonacci heap rỗng là `Φ(H) = 0`. Do đó, chi phí khấu hao của MAKE_HEAP bằng đúng chi phí thực tế `O(1)` của nó.

```cpp
MAKE_HEAP()
1. H.min_node = NULL
2. H.total_nodes = 0
3. H.root_list = NULL
4. return H
```

###  6.2. <a name='ChnmtnodemivoInsert'></a>Chèn một node mới vào (Insert)

Để chèn một node mới, ta chỉ việc chèn nó vào root list của Fibonacci Heap. Cụ thể ở pseudocode dưới đây.

```cpp
INSERT(H, x)
1. node.key = x
2. node.degree = 0
3. node.parent = NULL
4. node.child = NULL
5. node.left = NULL
6. node.right = NULL
7. node.mark = FALSE
8. Chèn node vào root list của H
9. if node.key < H.min_node.key then
10.      H.min_node = node
11. end if
12. H.total_nodes += 1
```
![insert](https://github.com/TrunkiEnqark/Algorithms/assets/89256879/909b75da-dc0d-4139-b732-028deca370b2)

#### <a name='Phntchthigianchy'></a>Phân tích thời gian chạy

Để xác định chi phí khấu hao của `INSERT(H, x)`, giả sử H là Heap Fibonacci đầu vào và H' là Heap Fibonacci sau khi thực hiện phép chèn. Khi đó, `t(H') = t(H) + 1` và `m(H') = m(H)`, và sự tăng của tiềm năng là:
`((t(H) + 1) + 2m(H)) - (t(H) + 2m(H)) = 1`
Vì chi phí thực tế là `O(1)`, chi phí khấu hao là `O(1) + 1 = O(1)`.

###  6.3. <a name='TmnodenhnhtFindmin'></a>Tìm node nhỏ nhất (Find min)

Nút nhỏ nhất của một Heap Fibonacci H được cho bởi con trỏ H.min_node, vì vậy chúng ta có thể tìm nút nhỏ nhất trong thời gian thực tế `O(1)`. Bởi vì tiềm năng của H không thay đổi, chi phí khấu hao của thao tác này bằng đúng chi phí thực tế `O(1)` của nó.

```cpp
FIND_MIN(H)
1. return H.min_node
```

###  6.4. <a name='Hpnht2FibonacciHeapUnion'></a>Hợp nhất 2 Fibonacci Heap (Union)

Thủ tục sau đây thực hiện hợp nhất (`union`) hai Fibonacci Heap H1 và H2, giải phóng H1 và H2 trong quá trình đó.

```cpp
UNION(H1, H2)
1. H = MAKE_HEAP()
2. H.min_node = H1.min_node
3. Nối root list của H2 với root list của H
4. H.min_node = minimum(H1.min_node, H2.min_node)
5. H.total_nodes = H1.total_nodes + H2.total_nodes
6. Giải phóng bộ nhớ cho H1 và H2
7. return H
```

#### <a name='Phntchthigianchy-1'></a>Phân tích thời gian chạy

Sự thay đổi về tiềm năng là:
```
Φ(H) - (Φ(H1) + Φ(H2))
= (t(H) + 2m(H)) - ((t(H1) + 2m(H1)) + (t(H2) + 2m(H2)))
= 0
```

- Sau khi hợp nhất, số lượng cây trong danh sách gốc của H bằng tổng số lượng cây của H1 và H2, nên `t(H) = t(H1) + t(H2)`.
- Tương tự, số lượng nút đánh dấu trong H bằng tổng số nút đánh dấu của H1 và H2, nên `m(H) = m(H1) + m(H2)`.
- Do đó, sự thay đổi về tiềm năng `Φ(H) - (Φ(H1) + Φ(H2)) = 0`.
- Do đó, chi phí thực tế của phép hợp nhất chỉ là `O(1)`.

###  6.5. <a name='TrchxutnodenhnhtExtractmin'></a>Trích xuất node nhỏ nhất (Extract min)

Ý tưởng chính:
1. Tìm nút có khóa nhỏ nhất, gọi `temp = min_node`. Điều này có thể thực hiện được trong O(1).
2. Loại bỏ nút `temp` khỏi danh sách gốc (root list) bằng cách cập nhật các con trỏ trong danh sách gốc.
3. Nối tất cả danh sách con (child list) của `temp` vào danh sách gốc hiện tại. Điều này có nghĩa các con của `temp` bây giờ trở thành các cây độc lập trong danh sách gốc.
4. Gọi thủ tục `CONSOLIDATE(H)` để hợp nhất tất cả các cây trong danh sách gốc có cùng bậc (`degree`) thành các cây mã nhị (binomial trees).
6. Cập nhật lại min_node
7. Trả về giá trị `key` của nút `temp` đã trích xuất.

```cpp
EXTRACT_MIN(H)
1. temp = H.min_node
2. if temp != NULL then
3.      Thêm các con của temp vào root list của H
4.      Xóa node temp ra khỏi root list của H
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
1. Xóa y ra khỏi root list của H
2. Nối y vào child list của x
3. x.degree += 1
4. y.mark = FALSE
```

![extract_min_a](https://github.com/TrunkiEnqark/Algorithms/assets/89256879/fac6242d-1c65-4eda-aef8-6bbe634a136f)
![extract_min_b](https://github.com/TrunkiEnqark/Algorithms/assets/89256879/51417e7e-d7fa-4b3c-b51d-18d3e8b9c140)

(a) Fibonacci heap H lúc đầu

(b) Nút 3 (nút nhỏ nhất) đã bị xóa

(c)-(m) Xây dựng lại H

#### <a name='Phntchthigianchy-1'></a>Phân tích thời gian chạy

Tiềm năng trước khi lấy ra node nhỏ nhất là `t(H) + 2m(H)`, và tiềm năng sau đó tối đa là `(D(n) + 1) + 2m(H)`, bởi vì tối đa `D(n) + 1` gốc còn lại và không có node nào bị *đánh dấu* trong quá trình thao tác. Do đó, chi phí khấu hao tối đa là:
```
O(D(n) + t(H)) + ((D(n) + 1) + 2m(H)) - (t(H) + 2m(H))
= O(D(n)) + O(t(H)) - t(H)
= O(D(n))
```

Giá trị lớn nhất của `D(n)` là `log(n)` (như đã nói ở phần trên). Nên có thể xem độ phức tạp thời gian của phần này là `O(log(n))`.

###  6.6. <a name='GimgitrcamtnodeDecreaseKey'></a>Giảm giá trị của một node (Decrease Key)

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
1. Xóa x ra khỏi child list của y
2. y.degree -= 1
2. Thêm x vào root list của H
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

####  <a name='Phntchthigianchy-1'></a>Phân tích thời gian chạy

Chúng ta sẽ chứng minh thời gian chạy của thuật toán này chỉ là `O(1)`.
Ta có thể thấy hàm `DECREASE_KEY` và `CUT` mỗi hàm chỉ tốn `O(1)`.
Hàm `CASCADING_CUT` có đệ quy nên độ phức tạp của nó là `O(c)` với `c` là số lần đệ quy.

- Ta vẫn sẽ sử dụng độ chênh lệnh của hàm tiềm năng trước và sau khi chạy để tính độ phức tạp. 
- Ta có thể thấy sau khi chạy thì ta sẽ có `t(H) + c` cây, với:
    - Ban đầu ta có `t(H)`.
    - `c - 1` cây được xây dựng nhờ hàm `CASCADING_CUT`.
    - Một cây có root là `x`.
- Và `m(H) - c + 2` node được đánh dấu, với:
    - `c - 1` node được xóa đánh dấu.
    - Có thể lần gọi `CASCADING_CUT` cuối cùng đã đánh dấu 1 node.

Ta có sự thay đổi của hàm tiềm năng như sau:
`((t(H) + c) + 2(m(H) - c + 2)) - (t(H) + 2m(H)) = 4 - c`
Nên độ phức tạp chung sẽ là:
`O(c) + 4 - c = O(1)`

###  6.7. <a name='XamtnodeDelete'></a>Xóa một node (Delete)

Đến đây thì việc xóa một node không còn là việc khó. Ta chỉ cần giảm node đó xuống giá trị nhỏ nhất sau đó trích xuất ra. Cụ thể như sau:

```cpp
DELETE(H, x)
1. DECREASE_KEY(H, x, -infinity)
2. EXTRACT_MIN(H)
```

Như đã phân tích thì hàm `DECREASE_KEY` tốn `O(1)` và `EXTRACT_MIN` tốn `O(log(n))`. Nên độ phức tạp chung sẽ là `O(log(n))`.

##  7. <a name='References'></a>References

> [Intro to Algorithm book](http://staff.ustc.edu.cn/~csli/graduate/algorithms/book6/chap21.htm)

> [Wikipedia](https://en.wikipedia.org/wiki/Fibonacci_heap)

> [Daniel](https://github.com/danielborowski/fibonacci-heap-python)