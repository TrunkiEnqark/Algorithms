#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &arr) {
    for (int i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        for (; j >= 0 && arr[j] > key; --j) 
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr) cin >> it;
    insertion_sort(arr);
    for (auto it : arr) cout << it << ' ';

    return 0;
}