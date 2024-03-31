#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
const int LG = 16; // 2^LG <= N

int n, a[N + 1], RSQ[LG + 1][N + 1];

void preprocess() {
    for (int i = 1; i <= n; ++i) RSQ[0][i] = a[i];
    for (int j = 1; j <= LG; ++j) 
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) 
            RSQ[j][i] = RSQ[j - 1][i] + RSQ[j - 1][i + (1 << (j - 1))];
}

int getSumRange(int l, int r) {
    int len = r - l + 1;
    int lg = __lg(len) + 1;
    int sum = 0;
    for (int i = 0; (1 << i) <= len; ++i) {
        if ((len >> i) & 1) {
            sum += RSQ[i][l]; 
            l += (1 << i);
        }
    }
    return sum;
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
        cout << getSumRange(l, r) << endl;
    }

    return 0;
}