#include <bits/stdc++.h>
using namespace std;

const int RUN = 32; 
  
void insertion_sort(vector<int> &arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;
        for (; j >= left && arr[j] > key; --j) 
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }
}
  
void merge(vector<int> &arr, int left, int mid, int right) {
    // size of left array and right array
    int sub_array_one = mid - left + 1;
    int sub_array_two = right - mid;
    
    // Create temp array
    vector<int> left_array(sub_array_one, -1);
    vector<int> right_array(sub_array_two, -1);

    // Copy data from arr
    for (int i = 0; i < sub_array_one; ++i) 
        left_array[i] = arr[left + i];
    for (int i = 0; i < sub_array_two; ++i)
        right_array[i] = arr[mid + 1 + i];

    // create 2 pointers of 2 arrays and 1 pointer of merged array
    int index_one = 0, index_two = 0;
    int index_merged_array = left;

    while (index_one < sub_array_one && index_two < sub_array_two) {
        if (left_array[index_one] < right_array[index_two]) {
            arr[index_merged_array] = left_array[index_one++];
        } else {
            arr[index_merged_array] = right_array[index_two++];
        }
        index_merged_array++;
    }

    for (; index_one < sub_array_one; ++index_one) 
        arr[index_merged_array++] = left_array[index_one];

    for (; index_two < sub_array_two; ++index_two) 
        arr[index_merged_array++] = right_array[index_two];
}
  
void tim_sort(vector<int> &arr) { 
    int n = arr.size();
    for (int i = 0; i < n; i += RUN) 
        insertion_sort(arr, i, min((i + RUN - 1), (n - 1))); 

    for (int size = RUN; size < n; size = 2 * size) { 
        for (int left = 0; left < n; left += 2 * size) { 
            int mid = left + size - 1; 
            int right = min((left + 2 * size - 1), (n - 1)); 
            if (mid < right) 
                merge(arr, left, mid, right); 
        } 
    } 
} 

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr) cin >> it;
    tim_sort(arr);
    for (auto it : arr) cout << it << ' ';

    return 0;
}