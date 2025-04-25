#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

const int MOD = 1e9 + 7;

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

int fibonacci(int n, int mod) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	Matrix F(2);
	F[0][0] = 1; F[0][1] = 1;
	F[1][0] = 1; F[1][1] = 0;
	F = F.pow(n - 1);
	return F[0][0];
}

int32_t main() {
	fast
	int n, x, y, p;
	std::cin >> n >> x >> y >> p;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int sum_initial = 0;
	for (int i = 0; i < n; i++) {
		sum_initial = (sum_initial + a[i]) % p;
	}
	if (x > 0) {
		sum_initial = (sum_initial * fibonacci(x + 2, p) - a[0] * fibonacci(x + 1, p) - a[n - 1] * fibonacci(x + 1, p)) % p;
		if (sum_initial < 0) sum_initial += p;
	}
	if (y > 0) {
		sum_initial = (sum_initial * fibonacci(y + 2, p) - a[0] * fibonacci(y + 1, p) - a[n - 1] * fibonacci(y + 1, p)) % p;
		if (sum_initial < 0) sum_initial += p;
	}
	std::cout << sum_initial << '\n';
}
