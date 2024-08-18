#include <bits/stdc++.h>

using namespace std;

class Mex {
private:
    map<int, int> frequency;
    set<int> missing_numbers;
    vector<int> A;

public:
    Mex(const vector<int>& A) : A(A) {
        for (int i = 0; i <= A.size(); i++)
            missing_numbers.insert(i);

        for (int x : A) {
            ++frequency[x];
            missing_numbers.erase(x);
        }
    }

    int mex() {
        return *missing_numbers.begin();
    }

    void update(int idx, int value) {
        if (--frequency[A[idx]] == 0)
            missing_numbers.insert(A[idx]);
        A[idx] = value;
        ++frequency[value];
        missing_numbers.erase(value);
    }
};

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
        Mex res = Mex(test);
        cout << res.mex() << '\n';
    }
}