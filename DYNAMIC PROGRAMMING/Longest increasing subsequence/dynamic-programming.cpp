#include <bits/stdc++.h>

using namespace std;

const int N = 1e3;

int n, a[N + 1], dp[N + 1];

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    for(int i = 1; i <= n; ++i) dp[i] = 1;

    for(int i = 2; i <= n; ++i) 
        for(int j = 1; j < i; ++j) 
            if(a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
    cout << *max_element(dp + 1, dp + n + 1);
}