#include <bits/stdc++.h>

using namespace std;

int F[100005];

void Fibo(int n = 1e5) {
    F[1] = 1;
    F[2] = 1;
    for (int i = 3; i <= n; ++i) 
        F[i] = F[i - 1] + F[i - 2];
}

int main() {
    Fibo();
    int n;
    cin >> n;
    cout << F[n];
}