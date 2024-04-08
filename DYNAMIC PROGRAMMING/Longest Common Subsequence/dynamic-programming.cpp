#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n, m, a[N], b[N], dp[N][N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];

    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }
    }

    cout << dp[n][m];
}