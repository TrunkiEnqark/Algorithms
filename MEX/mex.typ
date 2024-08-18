#set document(title: "MEX (Minimal Excluded) của một dãy số")
#set heading(numbering: "1.")
#set page(
  numbering: "1",
  header: align(right, [Code cung Kiến])
)
#set text(font: "New Computer Modern", size: 11pt)

#align(center)[
  #text(size: 20pt, weight: "bold")[
    MEX (Minimal Excluded) của một dãy số
  ]
]

= Định nghĩa

MEX (Minimal Excluded) của một dãy số là phần tử *không âm nhỏ nhất* không xuất hiện trong dãy đó. Ví dụ:

$ "mex"({1, 2, 3}) = 0 \
"mex"({0, 1, 2, 4}) = 3 \
"mex"({0, 1, 2, 3}) = 4 $

Lưu ý rằng MEX của một mảng có kích thước $N$ không bao giờ lớn hơn $N$.

= Truy vấn một lần
== Cài đặt cơ bản

Cách tiếp cận đơn giản nhất là sử dụng một tập hợp (set) để lưu trữ tất cả các phần tử trong mảng, sau đó kiểm tra các số từ 0 đến $N$ xem số nào đầu tiên không có trong tập hợp.

```cpp
int find_MEX(const vector<int>& nums) {
    set<int> s(nums.begin(), nums.end());

    int result = 0;
    while (s.find(result) != s.end())
        result++;
    return result;
}```
Độ phức tạp: $O(N log N)$.

== Cài đặt tối ưu hơn
Ta hoàn toàn có thể sử dụng một ```cpp vector<boolean>``` thay vì set:
```cpp
int find_MEX(const vector<int>& nums) {
    int max_ele = *max_element(nums.begin(), nums.end());
    vector<bool> marked(max_ele + 1, false);
    
    for (auto num : nums)
        marked[num] = true;

    int result = 0;
    while (marked[result])
        result++;
    return result;
}```

Độ phức tạp: $O(n)$

Cách này nhanh hơn nhưng chỉ hiệu quả khi tính MEX một lần. Nếu cần tính MEX nhiều lần với các thay đổi trên mảng, ta cần một cấu trúc dữ liệu tốt hơn.

= Truy vấn nhiều lần
== MEX với cập nhật mảng và truy vấn $O(1)$
- Khởi tạo:
  - Sử dụng cấu trúc dữ liệu set để xác định các giá trị bị mất và map để xác định tần số xuất hiện.
  - Thêm vào set các giá trị từ $1$ đến $n$ sau đó duyệt các phần tử trong mảng và xóa các phần tử có giá trị tương ứng trong set. Khi đó giá trị MEX lúc nào cũng là giá trị đầu tiên của set.
- Cập nhật:
  - Thực hiện update đơn giản như đoạn code phía dưới với độ phức tạp $O(log n)$.
- Truy vấn:
  - Đơn giản lúc nào cũng là giá trị đầu tiên của set.
```cpp
class Mex {
private:
    map<int, int> frequency;
    set<int> missing_numbers;
    vector<int> A;

public:
    Mex(const vector<int>& A) : A(A) {
        for (int i = 0; i <= A.size(); i++)
            missing_numbers.insert(i);

        for (int x : A) {
            ++frequency[x];
            missing_numbers.erase(x);
        }
    }

    int mex() {
        return *missing_numbers.begin();
    }

    void update(int idx, int value) {
        if (--frequency[A[idx]] == 0)
            missing_numbers.insert(A[idx]);
        A[idx] = value;
        ++frequency[value];
        missing_numbers.erase(value);
    }
};```

Cấu trúc này có độ phức tạp:
- Khởi tạo: $O(N log N)$
- Truy vấn: $O(1)$
- Cập nhật: $O(log N)$

// == Tính MEX trong một đoạn [l, r] 