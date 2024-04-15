#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 8, x = 13;
    int a[] = {1, 3, 4, 6, 7, 8, 9, 11};

    // two pointers
    int i = 0, j = n - 1;
    while (i <= j) {
        if (a[i] + a[j] == x) {
            cout << i + 1 << ' ' << j + 1 << endl;
            return 0;
        }
        if (a[i] + a[j] < x) i++;
            else j--; 
    }
}