#include <bits/stdc++.h>
using namespace std;

void count_sort(vector<int> &arr, int exp) {
    vector<int> result(arr.size(), 0);
    int count[10];
    memset(count, 0, sizeof count);
    for (int i = 0; i < arr.size(); ++i)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; ++i)
        count[i] += count[i - 1];
    
    for (int i = arr.size() - 1; i >= 0; --i) {
        result[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }   

    arr.swap(result);
}

void radix_sort(vector<int> &arr) {
    int n = arr.size();
    int max_ele = *max_element(arr.begin(), arr.end());
    for (int exp = 1; max_ele / exp > 0; exp *= 10) {
        count_sort(arr, exp);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr) cin >> it;
    radix_sort(arr);
    for (auto it : arr) cout << it << ' ';

    return 0;
}