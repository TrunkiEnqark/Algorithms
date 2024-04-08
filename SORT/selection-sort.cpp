#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &arr) {
    for (int i = 0; i < arr.size() - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[min_index]) 
                min_index = j;
        }
        swap(arr[i], arr[min_index]);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr) cin >> it;
    selection_sort(arr);
    for (auto it : arr) cout << it << ' ';

    return 0;
}