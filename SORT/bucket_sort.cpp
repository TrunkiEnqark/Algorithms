// use for float array
// Time complexity: O(n^2)

#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<float> &bucket) {
    for (int i = 1; i < bucket.size(); ++i) {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

void bucket_sort(vector<float> &arr) {
    int n = arr.size();
    vector<float> b[n];

    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) 
        insertion_sort(b[i]);

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b[i].size(); j++) {
            arr[index++] = b[i][j];
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<float> arr(n);
    for (auto &it : arr) cin >> it;
    bucket_sort(arr);
    for (auto it : arr) cout << it << ' ';

    return 0;
}