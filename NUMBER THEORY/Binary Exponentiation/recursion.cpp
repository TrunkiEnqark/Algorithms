#include <bits/stdc++.h>

using namespace std;

// (a^n) % MOD
int64_t POW(int64_t a, int64_t n, int64_t MOD) {
    if (n == 0) return 1;

    int64_t temp = POW(a, n/2, MOD);
    if (n % 2 == 0) return temp * temp % MOD;
    return ((a * temp) % MOD) * temp % MOD;
}

int main() {
    int64_t a = 10005, n = 100000000009, MOD = 1000000007;
    cout << POW(a, n, MOD);

    return 0;
}