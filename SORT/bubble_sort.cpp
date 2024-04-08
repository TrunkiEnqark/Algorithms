#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &arr) {
    for (int i = 0; i < arr.size() - 1; ++i) {
        for (int j = i + 1; j < arr.size(); ++j) 
            if (arr[i] > arr[j]) 
                swap(arr[i], arr[j]);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr) cin >> it;
    bubble_sort(arr);
    for (auto it : arr) cout << it << ' ';

    return 0;
}