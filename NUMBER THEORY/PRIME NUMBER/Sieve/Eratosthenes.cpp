#include <bits/stdc++.h>

using namespace std;

const int lim = 1e6;

bool isPrime[lim + 5];

void Eratosthenes(int n = lim) {
    memset(isPrime, true, sizeof isPrime);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i*i <= n; ++i) 
        if (isPrime[i]) {
            for (int j = i*i; j <= n; j += i) isPrime[j] = false;
        }
}

int main() {
    Eratosthenes();
    for (int i = 1; i <= 100; ++i)
        if (isPrime[i]) cout << i << ' ';

    return 0;
}