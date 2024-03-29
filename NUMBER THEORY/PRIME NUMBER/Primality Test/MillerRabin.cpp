#include <bits/stdc++.h>

using namespace std;

long long POW(long long a, long long n, long long MOD) {
    long long res = 1;
    a %= MOD;
    while (n) {
        if (n&1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return res;
}

bool MillerTest(long long d, long long n) {
    // random in [2..n - 2]
    long long a = rand() % (n - 4) + 2;

    // calculate (a^d) % n
    long long x = POW(a, d, n);
    if (x == 1 || x == n - 1) return true;

    while (d != n - 1) {
        x = (x * x) % n;
        d <<= 1;

        if (x == 1) return false;
        if (x == n - 1) return true;
    }
    return false;
}

bool isPrime(long long n, int k = 100) {
    // Corner cases
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;

    long long d = n - 1;
    while (d%2 == 0) d /= 2;

    while (k--) {
        if (!MillerTest(d, n)) return false;
    }

    return true;
}

int main() {
    long long n;
    cin >> n;
    if (isPrime(n)) cout << "YES\n";
        else cout << "NO\n";

    return 0;
}