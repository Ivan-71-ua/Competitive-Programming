#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

const int MOD = 1000000007;

struct Matrix {
	int m[4][4];
	Matrix() {
		memset(m, 0, sizeof(m));
	}
	Matrix operator*(const Matrix &other) const {
		Matrix result;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				for (int k = 0; k < 4; k++)
					result.m[i][j] = (result.m[i][j] + m[i][k] * other.m[k][j]) % MOD;
		return result;
	}
};

Matrix matrix_pow(Matrix base, int exp) {
	Matrix result;
	for (int i = 0; i < 4; ++i)
		result.m[i][i] = 1;
	while (exp > 0) {
		if (exp % 2 == 1) {
			result = result * base;
		}
		base = base * base;
		exp /= 2;
	}
	return result;
}

int32_t main() {
	fast
	int n;
	std::cin >> n;
	Matrix T;
	T.m[0][1] = T.m[0][2] = T.m[0][3] = 1;
	T.m[1][0] = T.m[1][2] = T.m[1][3] = 1;
	T.m[2][0] = T.m[2][1] = T.m[2][3] = 1;
	T.m[3][0] = T.m[3][1] = T.m[3][2] = 1;
	Matrix result = matrix_pow(T, n);
	std::cout << result.m[3][3] << '\n';
}
