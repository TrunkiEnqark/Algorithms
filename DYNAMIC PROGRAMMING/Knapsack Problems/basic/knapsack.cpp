#include <bits/stdc++.h>

using namespace std;

const int max_weight = 1e5;
const int max_items = 100;

int N, W, weight[max_items + 1], value[max_items + 1];
long long dp[max_items + 1][max_weight + 1];

int main() {
    cin >> N >> W;
    for (int i = 1; i <= N; ++i) {
        cin >> weight[i] >> value[i];
    }

    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= W; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j - weight[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    cout << dp[N][W];

    return 0;
}