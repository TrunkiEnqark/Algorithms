#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

/* 
    S[1..length(s)] == T[i - length(S) + 1..i]
*/

string S, T;
int match[N], kmp[N];

int main() {
    cin >> T >> S;
    int n = S.size(); 
    int m = T.size();
    S = '#' + S;
    T = '$' + T;

    // calculate KMP
    int k = kmp[1] = 0;
    for (int i = 2; i <= n; ++i) {
        while (k > 0 && S[i] != S[k + 1]) k = kmp[k];
        if (S[i] == S[k + 1]) kmp[i] = ++k;
        else kmp[i] = 0;
    }

    // calculate match
    k = 0;
    for (int i = 1; i <= m; ++i) {
        while (k > 0 && T[i] != S[k + 1]) k = kmp[k];
        if (T[i] == S[k + 1]) match[i] = ++k;
        else match[i] = 0;
        
        // Found S in T[i - length(S) + 1..i]
        if (match[i] == n) {
            cout << i - n + 1 << ' ';
        }
    }

    return 0;
}