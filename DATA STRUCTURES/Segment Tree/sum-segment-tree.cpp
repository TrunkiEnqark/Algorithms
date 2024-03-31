#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

class SegmentTree {
private:
    int seg[N * 4];
public:
    SegmentTree() {
        fill(seg, seg + N * 4, 0);
    }

    void Build(int arr[], int id, int l, int r) {
        if (l > r) return;

        if (l == r) {
            seg[id] = arr[l];
            return;
        }

        int mid = (l + r) / 2;
        Build(arr, id * 2, l, mid);
        Build(arr, id * 2 + 1, mid + 1, r);
        seg[id] = seg[id * 2] + seg[id * 2 + 1];
    }

    // Get minimum value in [L, R]
    int get_sum(int id, int l, int r, int u, int v) {
        if (l > v || r < u || l > r) return 0;

        if (u <= l && r <= v) return seg[id];

        int mid = (l + r) / 2;
        return get_sum(id * 2, l, mid, u, v) + get_sum(id * 2 + 1, mid + 1, r, u, v);
    }
};

int main() {
    int a[] = {0, 100, 5, 8, -9, 4, 76, -3, 0};
    int n = sizeof(a) / sizeof(a[0]) - 1;
    SegmentTree seg;
    seg.Build(a, 1, 1, n);
    cout << seg.get_sum(1, 1, n, 2, 4) << endl;
    cout << seg.get_sum(1, 1, n, 4, 8) << endl;

    return 0;
}