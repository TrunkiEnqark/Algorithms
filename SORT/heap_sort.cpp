#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i) { 
	int largest = i; // Initialize largest as root 
	int l = 2*i + 1; // left = 2*i + 1 
	int r = 2*i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && arr[l] > arr[largest]) 
		largest = l; 

	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest]) 
		largest = r; 

	// If largest is not root 
	if (largest != i) { 
		swap(arr[i], arr[largest]); 
		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest); 
	} 
} 

void heap_sort(vector<int> &arr) { 
	// Build heap 
	for (int i = arr.size() / 2 - 1; i >= 0; --i) 
		heapify(arr, arr.size(), i); 

	// One by one extract an element from heap 
	for (int i = arr.size() - 1; i >= 0; --i) { 
		swap(arr[0], arr[i]); 
		heapify(arr, i, 0); 
	} 
} 

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr) cin >> it;
    heap_sort(arr);
    for (auto it : arr) cout << it << ' ';
	return 0;
}