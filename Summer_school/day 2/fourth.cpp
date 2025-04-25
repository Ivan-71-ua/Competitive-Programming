#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long
const int MOD = 1000000007;

int count_ones(int x) {
	int count = 0;
	while (x > 0) {
		count += x & 1;
		x >>= 1;
	}
	return count;
}

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
	fast
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	Matrix T(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (count_ones(a[i] ^ a[j]) % 3 == 0) {
				T[i][j] = 1;
			}
		}
	}
	Matrix result = T.pow(k - 1);
	int total_sequences = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			total_sequences = (total_sequences + result[i][j]) % MOD;
		}
	}
	std::cout << total_sequences << '\n';
}
