#include <bits/stdc++.h>

using namespace std;

// (a^n) % MOD
int64_t POW(int64_t a, int64_t n, int64_t MOD) {
    int64_t result = 1ll;
    a %= MOD;
    while (n) {
        if (n&1) result = (result * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return result;
}

int main() {
    int64_t a = 10005, n = 100000000009, MOD = 1000000007;
    cout << POW(a, n, MOD);

    return 0;
}