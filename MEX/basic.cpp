#include <bits/stdc++.h>

using namespace std;

// O(n log n)
int find_MEX(const vector<int>& nums) {
    set<int> s(nums.begin(), nums.end());

    int result = 0;
    while (s.find(result) != s.end())
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