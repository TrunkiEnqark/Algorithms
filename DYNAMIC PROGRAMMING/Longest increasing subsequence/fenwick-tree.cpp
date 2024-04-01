#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
vector<int> a, b;

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

    void update(int idx) {
        int val = getQuery(idx - 1) + 1;
        for (; idx <= n; idx += idx & (idx)) 
            bit[idx] = max(bit[idx], val);
    }
};

FenwickTree BIT;

int main() {
    cin >> n;
    a.resize(n, 0);
    b.resize(n, 0);
    for (int i = 0; i < n; ++i) cin >> a[i], b[i] = a[i];
    sort(b.begin(), b.end());
    unique(b.begin(), b.end());
    for (int i = 0; i < n; ++i) 
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;

    n = *max_element(a.begin(), a.end());
    // for (auto it : a) cout << it << ' ';
    // cout << endl;

    for (int i = 0; i < a.size(); ++i) {
        BIT.update(a[i]);
    }
    
    cout << BIT.getQuery(n);

    return 0;
}