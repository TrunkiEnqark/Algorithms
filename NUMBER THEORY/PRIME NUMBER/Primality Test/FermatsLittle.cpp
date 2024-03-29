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

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

bool isPrime(long long n, int k = 10) {
    // Corner cases
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;

    while (k--) {
        // random in [2..n - 2]
        long long a = rand() % (n - 4) + 2;

        if (gcd(n, a) != 1) return false;

        if (POW(a, n - 1, n) != 1) return false;
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