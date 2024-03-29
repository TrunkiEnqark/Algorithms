#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

class Matrix {
private:
    int matrix[2][2];

    Matrix operator * (const Matrix &other) {
        Matrix result = Matrix();
        
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    result.matrix[i][k] = (result.matrix[i][k] + 1ll * matrix[i][j] * other.matrix[j][k]) % MOD;
                }
            }
        }
        return result;
    }
public:
    Matrix() {
        memset(matrix, 0, sizeof matrix);
    }

    void base_fibo() {
        matrix[0][0] = 0;
        matrix[0][1] = matrix[1][0] = matrix[1][1] = 1;
    }

    int64_t get_fibo() {
        return matrix[1][0] % MOD;
    }

    Matrix POW(int64_t n) {
        Matrix result = Matrix();
        result.matrix[0][0] = result.matrix[1][1] = 1;
        Matrix a = *this;
        while (n) {
            if (n&1) result = result * a;
            n >>= 1;
            a = a * a;
        }
        return result;
    }
};

int main() {
    int64_t n;
    cin >> n;
    Matrix base;
    base.base_fibo();
    Matrix result = base.POW(n);
    cout << result.get_fibo();

    return 0;
}   