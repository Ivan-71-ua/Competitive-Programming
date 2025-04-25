#include <bits/stdc++.h>
#define int long long

int MOD;

struct Matrix {
    std::vector<std::vector<int>> mat;
    int size;

    Matrix(int n) : size(n) {
        mat.resize(n, std::vector<int>(n, 0));
    }

    std::vector<int>& operator[](int idx) {
        return mat[idx];
    }

    Matrix operator*(const Matrix &other) const {
        Matrix result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    result[i][j] = (result[i][j] + mat[i][k] * other.mat[k][j]) % MOD;
                }
            }
        }
        return result;
    }

    Matrix pow(int exp) const {
        Matrix result(size);
        Matrix base = *this;
        for (int i = 0; i < size; i++) {
            result[i][i] = 1;
        }
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = result * base;
            }
            base = base * base;
            exp /= 2;
        }
        return result;
    }
};

int32_t main() {
    int n, k, l, m;
    std::cin >> n >> k >> l >> m;
    MOD = m;

    int size = 1LL << l;
    Matrix T(size);


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (((i & j) | k) == k) {
                T[i][j] = 1;
            }
        }
    }

    Matrix result = T.pow(n - 1);

  
    int total_sequences = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            total_sequences = (total_sequences + result[i][j]) % MOD;
        }
    }

    total_sequences = (total_sequences * size) % MOD;  

    std::cout << total_sequences << std::endl;
    return 0;
}
