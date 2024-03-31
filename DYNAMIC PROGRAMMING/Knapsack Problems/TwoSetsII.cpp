#include <bits/stdc++.h>

using namespace std;

const int MaxValue = 125250;
const int MaxN = 505;
const int MOD = 1e9 + 7;

int dp[MaxN][MaxValue + 5], total, n;

int main() {
    cin >> n;
    int sum = n * (n + 1) / 2;
    if(sum%2 == 1) {
        cout << 0;
        return 0;
    }
    sum /= 2;

    dp[0][0] = 1;
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j <= sum; ++j) {
            dp[i][j] = dp[i - 1][j];
            if(j - i >= 0) {
                dp[i][j] += dp[i - 1][j - i];
                dp[i][j] %= MOD;
            }
        }
    }

    cout << dp[n - 1][sum];
}