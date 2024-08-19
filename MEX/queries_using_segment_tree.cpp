#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

class SegmentTree {
private:
    int seg[N * 4];
public:
    SegmentTree() {
        memset(seg, 0, sizeof seg);
    }

    void set(int id, int l, int r, int i, int val) {
        if (l > i || r < i || l > r) return;
        
        if (l == r) {
            seg[id] = val;
            return;
        }

        int mid = (l + r) / 2;
        set(id*2, l, mid, i, val);
        set(id*2 + 1, mid + 1, r, i, val);
        seg[id] = min(seg[id*2], seg[id*2 + 1]);
    }

    int find_mex(int id, int l, int r, int val) {
        if (l > r) return 0;

        if (l == r) return l;

        int left_node = seg[id*2];
        int right_node = seg[id*2 + 1];
        int mid = (l + r) / 2;
        if (val > left_node) {
            return find_mex(id*2, l, mid, val);
        }
        return find_mex(id*2 + 1, mid + 1, r, val);
    }
};

int main() {
    vector<int> A = {0, 0, 1, 2, 4, 6};
    int n = A.size();
    int q;
    cin >> q;
    vector<vector<pair<int, int>>> queries(n + 1);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        queries[r].push_back({l, i});
    }
    SegmentTree tree;
    vector<int> res(q);
    int m = *max_element(A.begin(), A.end());
    for (int i = 0; i < n; ++i) {
        tree.set(1, 0, m, A[i], i + 1);
        for (auto [l, idx] : queries[i]) {
            res[idx] = tree.find_mex(1, 0, m, l);
        }
    }
    for (auto r : res) 
        cout << r << endl;
}