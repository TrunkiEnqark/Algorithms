#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int X = 1e6 + 6;

int n, x, c[N], dp[X];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> x;
    for(int i = 1; i <= n; ++i) cin >> c[i];
    fill(dp + 1, dp + x + 1, 1e9);
    dp[0] = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = c[i]; j <= x; ++j) {
            dp[j] = min(dp[j], dp[j - c[i]] + 1);
        }
    }

    cout << (dp[x] == 1e9 ? -1 : dp[x]);
}