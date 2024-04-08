#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
const int inf = 1e9;
int n, a[N + 1], b[N + 1];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    fill(b, b + N, inf);

    int result = 1;
    for (int i = 1; i <= n; ++i) {
        int j = lower_bound(b + 1, b + n + 1, a[i]) - b;
        b[j] = a[i];
        result = max(result, j);
    }
    cout << result;

    return 0;
}