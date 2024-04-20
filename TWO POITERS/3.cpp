#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 8;
    long long s = 21;
    int a[] = {1, 3, 4, 6, 7, 8, 9, 11};

    // two pointers
    // i <= j
    int i = 0, j = 0, res = 0;
    long long sum = 0;
    while (j < n) {
        sum += a[j];

        while (sum > s && i < j) {
            sum -= a[i];
            i++;
        } 
        // cout << i << ' ' << j << endl;
        res = max(res, j - i + 1);

        j++;
    }
    cout << res;
}