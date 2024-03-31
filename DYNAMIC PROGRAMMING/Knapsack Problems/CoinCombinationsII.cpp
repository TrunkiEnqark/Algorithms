#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int X = 1e6 + 6;
const int MOD = 1e9 + 7;

int n, x, c[N], dp[X];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> x;
    for(int i = 1; i <= n; ++i) cin >> c[i];

    dp[0] = 1;
    for(int i = 1; i <= n; ++i) { 
        for(int w = 1; w <= X; ++w) 
            if(w - c[i] >= 0) {
                dp[w] += dp[w - c[i]];
                dp[w] %= MOD;
            }
    }
    cout << dp[x];
}