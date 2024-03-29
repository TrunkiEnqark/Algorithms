#include <bits/stdc++.h>

using namespace std;

const int lim = 1e6;

bool isPrime[lim + 5];

/*
    Condition 1:
        if (4*x*x + y*y) % 12 == 1 or 5
    Condition 2:
        if (3*x*x + y*y) % 12 == 7
    Condition 3:
        if (3*x*x - y*y) % 12 == 11
*/

void SieveOfAtkin(int n = lim) {
    memset(isPrime, false, sizeof isPrime);
    isPrime[2] = isPrime[3] = true;

    for (int x = 1; x*x <= n; ++x) {
        for (int y = 1; y*y <= n; ++y) {
            // Condition 1
            int p = (4 * x * x) + y * y;
            if (p <= n && (p % 12 == 1 || p % 12 == 5))
                isPrime[p] ^= true;
            // Condition 2
            p = (3 * x * x) + y * y;
            if (p <= n && p % 12 == 7) 
                isPrime[p] ^= true;
            // Condition 3
            p = (3 * x * x) - y * y;
            if (x > y && p <= n && p % 12 == 11)
                isPrime[p] ^= true;
        }
    }

    // Square number
    for (int r = 5; r*r <= n; ++r) {
        if (isPrime[r]) 
            for (int i = r*r; i <= n; i += r*r) 
                isPrime[i] = false;
    }
}

int main() {
    SieveOfAtkin();
    for (int i = 1; i <= 100; ++i)
        if (isPrime[i]) cout << i << ' ';

    return 0;
}