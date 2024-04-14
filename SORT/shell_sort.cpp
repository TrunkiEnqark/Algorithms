#include <bits/stdc++.h>
using namespace std;

void shell_sort(vector<int> &arr) {
    int n = arr.size();
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j = i;            
            for (; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr) cin >> it;
    shell_sort(arr);
    for (auto it : arr) cout << it << ' ';

    return 0;
}