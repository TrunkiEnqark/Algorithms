#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3 || n == 5) return true;
    if (n%2 == 0 || n%3 == 0 || n%5 == 0) return false;

    for (int i = 6; i*i <= n; i += 6) 
        if (n % (i - 1) == 0 || n % (i + 1) == 0) return false;
    
    return true;
}

int main() {
    int n;
    cin >> n;
    if (isPrime(n)) cout << "YES\n";
        else cout << "NO\n";

    return 0;
}