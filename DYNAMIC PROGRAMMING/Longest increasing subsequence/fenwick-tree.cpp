#include <bits/stdc++.h>

using namespace std;

const int N = 3e4 + 5;

int n;
vector<int> a;

class FenwickTree {
private:
    int bit[N];
public:
    FenwickTree() {
        memset(bit, 0, sizeof bit);
    }

    int getQuery(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & (-idx)) res = max(res, bit[idx]);
        return res;
    }

    void update(int idx, int val) {
        for (; idx < N; idx += idx & (-idx)) 
            bit[idx] = max(bit[idx], val);
    }
};

FenwickTree BIT;

int main() {
    cin >> n;
    a.resize(n);
    for (int &it : a) cin >> it;

    vector<int> b(a);
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    for (int i = 0; i < n; ++i) 
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;

    int res = 0;
    for (auto i : a) {
        int val = BIT.getQuery(i - 1) + 1;
        BIT.update(i, val);
        res = max(res, val);
    }
    
    cout << res;

    return 0;
}