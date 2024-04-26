# Fibonacci Heaps

# Fibonacci Heaps Variables
- ``total_nodes``: Số lượng node trong heap
- ``root_list``: Gốc của cây đầu tiên trong heaps
- ``min_node``: node chứa giá trị nhỏ nhất
- Trong ``Node`` gồm:
    - ``key``: Giá trị của node
    - ``parent``, ``child``, ``left``, ``right``: Dùng để trỏ đến 4 hướng của node 
    - ``degree``: Bậc của node
    - ``mark``: Có bị mất một nút con kể từ lần cuối cùng nó trở thành nút con của một nút khác hay không.

# Fibonacci Heaps Methods
- ``get_min()``: Lấy giá trị nhỏ nhất trong heaps
- ``extract_min()``: Trả về giá trị nhỏ nhất hiện tại và xóa node này ra khỏi heaps
- ``insert(key)``: Chèn thêm một ``node`` có giá trị ``key`` vào heaps
- ``decrease_key(x, k)``: Biến đổi ``key`` node ``x`` thành ``k``  
- ``merge(h2)``: Hợp nhất cây ``h2`` vào ``root_list``

References:

[Intro to Algorithm book](http://staff.ustc.edu.cn/~csli/graduate/algorithms/book6/chap21.htm)

[Wikipedia](https://en.wikipedia.org/wiki/Fibonacci_heap)