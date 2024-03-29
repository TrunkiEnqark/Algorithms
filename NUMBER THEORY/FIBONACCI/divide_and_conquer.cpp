#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;
unordered_map<int64_t, int64_t> F;

int64_t fib(int64_t n) {
    if (F.count(n)) return F[n];

    int64_t k = n/2;
    if (n%2 == 0) {
        return F[n] = (fib(k) * fib(k) + fib(k - 1) * fib(k - 1)) % MOD;
    }
    return F[n] = (fib(k) * fib(k - 1) + fib(k) * fib(k + 1)) % MOD;
}

int main() {
    F[0] = F[1] = 1;
    int64_t n;
    cin >> n;
    if (n == 0) cout << 0;
        else cout << fib(n - 1);
}