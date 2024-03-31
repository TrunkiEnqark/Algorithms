#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int W = 1e5 + 5;

int n, w, price[N], pages[N], dp[N][W];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> w;
    for(int i = 0; i < n; ++i) cin >> price[i];
    for(int i = 0; i < n; ++i) cin >> pages[i];

    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= w; ++j) {
            dp[i][j] = dp[i - 1][j];
            if(j - price[i - 1] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i - 1]] + pages[i - 1]);
        }
    }

    cout << dp[n][w];
}

// https://cses.fi/problemset/task/1158