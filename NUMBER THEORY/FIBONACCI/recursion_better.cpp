#include <bits/stdc++.h>

using namespace std;

int F[10005];

int fibo(int n) {
    if (n == 1 || n == 2) return 1;
    if (F[n]) return F[n];
    return F[n] = fibo(n - 1) + fibo(n - 2);
}

int main() {
    int n;
    cin >> n;
    cout << fibo(n);
}