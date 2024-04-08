#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 5;

string a, b;
int dp[N][N];

int main() {
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    a = "#" + a;
    b = "#" + b;

    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }
    }

    int i = n, j = m;
    string res;
    while (i >= 1 && j >= 1) {
        if (a[i] == b[j]) {
            res = a[i] + res;
            i--;
            j--;
        } else {
            if (dp[i - 1][j] > dp[i][j - 1]) 
                i--;
            else 
                j--;
        }
    }

    cout << res;

    return 0;
}