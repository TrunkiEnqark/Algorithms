#include <bits/stdc++.h>

using namespace std;

// O(n)
int find_MEX(const vector<int>& nums) {
    int max_ele = *max_element(nums.begin(), nums.end());
    vector<bool> marked(max_ele + 1, false);
    
    for (auto num : nums)
        marked[num] = true;

    int result = 0;
    while (marked[result])
        result++;
    return result;
}

int main() {
    vector<vector<int>> tests = {
        {0, 1, 2, 4, 5},
        {0, 1, 2, 3, 4},
        {1, 2, 3, 4, 5}
    };
    for (auto test : tests) {
        cout << "MEX of {";
        for (int i = 0; i < test.size() - 1; i++) cout << test[i] << ", ";
        cout << test.back() << "} is ";
        cout << find_MEX(test) << '\n';
    }
}