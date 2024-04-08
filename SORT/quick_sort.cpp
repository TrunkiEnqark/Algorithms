#include <bits/stdc++.h>
using namespace std;

int partition (vector<int> &arr, int left, int right) { 
	int pivot = arr[right]; 
	int i = left - 1; 

	for (int j = left; j <= right - 1; j++) { 
		if (arr[j] < pivot) { 
			swap(arr[++i], arr[j]); 
		} 
	} 
	swap(arr[i + 1], arr[right]); 
	return i + 1; 
} 

void quick_sort(vector<int> &arr, int left, int right) { 
	if (left < right) { 
		int pi = partition(arr, left, right); 
		quick_sort(arr, left, pi - 1); 
		quick_sort(arr, pi + 1, right); 
	} 
} 

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr) cin >> it;
    quick_sort(arr, 0, arr.size() - 1);
    for (auto it : arr) cout << it << ' ';
	return 0;
}