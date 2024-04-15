#include <bits/stdc++.h>

using namespace std;

int main() {
    int a[] = {1, 3, 4, 6, 8};
    int n = sizeof(a) / sizeof(a[0]);
    int b[] = {2, 5, 7};
    int m = sizeof(b) / sizeof(b[0]);

    int c[n + m];
    // two pointers
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) 
        if (a[i] > b[j]) {
            c[k++] = b[j++];
        } else {
            c[k++] = a[i++];
        }

    while (i < n) 
        c[k++] = a[i++];

    while (j < m) 
        c[k++] = b[j++];

    for (k = 0; k < n + m; ++k) 
        cout << c[k] << ' ';
}