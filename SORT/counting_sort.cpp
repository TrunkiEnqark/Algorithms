#include <bits/stdc++.h>
using namespace std;

void counting_sort(vector<int> &arr) {
    // 0 <= max(a) <= 10^7 => ok
    int max_element_array = *max_element(arr.begin(), arr.end());
    vector<int> cnt(max_element_array + 1, 0);

    for (int i = 0; i < arr.size(); ++i)
        cnt[arr[i]]++;
    
    int iter = 0;
    for (int i = 0; i <= max_element_array; ++i)
        if (cnt[i] > 0) {
            for (int _ = 0; _ < cnt[i]; ++_)
                arr[iter++] = i;
        }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr) cin >> it;
    counting_sort(arr);
    for (auto it : arr) cout << it << ' ';

    return 0;
}