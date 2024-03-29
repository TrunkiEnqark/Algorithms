#include <bits/stdc++.h>

using namespace std;

const double phi = 1.6180339;
const int fib[6] = {0, 1, 1, 2, 3, 5};

int fibo(int n) {
    if (n < 6) return fib[n];
    int res = 5;
    while (n-- > 5) {
        res = round(res * phi);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << fibo(n);

    return 0;
}