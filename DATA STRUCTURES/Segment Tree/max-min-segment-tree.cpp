#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
const int inf = 1e9; // infinity

class SegmentTree {
private:
    int seg_min[N * 4];
    int seg_max[N * 4];
public:
    SegmentTree() {
        fill(seg_min, seg_min + N * 4, inf);
        fill(seg_max, seg_max + N * 4, -inf);
    }

    void Build(int arr[], int id, int l, int r) {
        if (l > r) return;

        if (l == r) {
            seg_min[id] = arr[l];
            seg_max[id] = arr[l];
            return;
        }

        int mid = (l + r) / 2;
        Build(arr, id * 2, l, mid);
        Build(arr, id * 2 + 1, mid + 1, r);
        seg_min[id] = min(seg_min[id * 2], seg_min[id * 2 + 1]);
        seg_max[id] = max(seg_max[id * 2], seg_max[id * 2 + 1]);
    }

    // Get minimum value in [L, R]
    int get_min(int id, int l, int r, int u, int v) {
        if (l > v || r < u || l > r) return inf;

        if (u <= l && r <= v) return seg_min[id];

        int mid = (l + r) / 2;
        return min(get_min(id * 2, l, mid, u, v), get_min(id * 2 + 1, mid + 1, r, u, v));
    }

    // Get maximum value in [L, R]
    int get_max(int id, int l, int r, int u, int v) {
        if (l > v || r < u || l > r) return -inf;

        if (u <= l && r <= v) return seg_max[id];

        int mid = (l + r) / 2;
        return max(get_max(id * 2, l, mid, u, v), get_max(id * 2 + 1, mid + 1, r, u, v));
    }
};

int main() {
    int a[] = {0, 100, 5, 8, -9, 4, 76, -3, 0};
    int n = sizeof(a) / sizeof(a[0]) - 1;
    SegmentTree seg;
    seg.Build(a, 1, 1, n);
    cout << n << endl;
    cout << seg.get_min(1, 1, n, 2, 4) << endl;
    cout << seg.get_max(1, 1, n, 4, 8) << endl;

    return 0;
}