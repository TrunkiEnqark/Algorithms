#include <bits/stdc++.h>
using namespace std;

void maxMin(vector<int> &arr, int &bingo, int &next_bingo) {
    for (int i = 1; i < arr.size(); i++) {
        bingo = min(bingo, arr[i]);
        next_bingo = max(next_bingo, arr[i]);
    }
}
 
void bingo_sort(vector<int>& arr) {
    int n = arr.size();
    int bingo = arr[0];
    int next_bingo = arr[0];
    maxMin(arr, bingo, next_bingo);
    
    int largest_element = next_bingo;
    int next_element_position = 0;

    while (bingo < next_bingo) {
        int startPos = next_element_position;
        for (int i = startPos; i < n; i++) {
            if (arr[i] == bingo) {
                swap(arr[i], arr[next_element_position]);
                next_element_position = next_element_position + 1;
            } else {
                if (arr[i] < next_bingo)
                    next_bingo = arr[i];
            }
        }
        bingo = next_bingo;
        next_bingo = largest_element;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr) cin >> it;
    bingo_sort(arr);
    for (auto it : arr) cout << it << ' ';

    return 0;
}