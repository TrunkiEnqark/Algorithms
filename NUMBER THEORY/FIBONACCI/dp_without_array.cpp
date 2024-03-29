#include <bits/stdc++.h>

using namespace std;

int fibo(int n) {
    int a = 1, b = 1, c;
    if (n == 1) return a;
    if (n == 2) return b;
    for (int i = 3; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int n;
    cin >> n;
    cout << fibo(n);
}