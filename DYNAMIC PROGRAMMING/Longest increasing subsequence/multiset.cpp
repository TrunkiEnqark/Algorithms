#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
const int inf = 1e9;

int n, a[N + 1];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    multiset<int> ms;
    ms.insert(a[1]);
    for (int i = 2; i <= n; ++i) {
        ms.insert(a[i]);
        auto it = ms.lower_bound(a[i]);
        it++;
        if (it != ms.end()) ms.erase(it);
    }
    cout << ms.size();

    return 0;
}