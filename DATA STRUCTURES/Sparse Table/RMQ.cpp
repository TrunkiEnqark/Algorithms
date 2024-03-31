#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
const int LG = 16; // 2^LG <= N

int n, a[N + 1], RMQ[LG + 1][N + 1];

void preprocess() {
    for (int i = 1; i <= n; ++i) RMQ[0][i] = a[i];
    for (int j = 1; j <= LG; ++j) 
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) 
            RMQ[j][i] = min(RMQ[j - 1][i], RMQ[j - 1][i + (1 << (j - 1))]);
}

int getMinRange(int l, int r) {
    int lg = __lg(r - l + 1);
    return min(RMQ[lg][l], RMQ[lg][r - (1 << lg) + 1]);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    preprocess();
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << getMinRange(l, r) << endl;
    }

    return 0;
}