#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

const int MOD = 1000000007;

struct Matrix {
	int m[3][3];
	Matrix() {
		memset(m, 0, sizeof(m));
	}
	Matrix operator*(const Matrix &other) const {
		Matrix result;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				for (int k = 0; k < 3; ++k)
					result.m[i][j] = (result.m[i][j] + m[i][k] * other.m[k][j]) % MOD;
		return result;
	}
};

Matrix matrix_pow(Matrix base, int exp) {
	Matrix result;
	for (int i = 0; i < 3; ++i)
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
	fast;
	int a, b, c, n;
	std::cin >> a >> b >> c >> n;
	if (n == 1) {
		std::cout << a;
	}
	else if (n == 2) {
		std::cout << b;
	}
	else if (n == 3) {
		std::cout << c;
	} 
	else {
		Matrix T;
		T.m[0][0] = 1; T.m[0][1] = 1; T.m[0][2] = 1;
		T.m[1][0] = 1; T.m[1][1] = 0; T.m[1][2] = 0;
		T.m[2][0] = 0; T.m[2][1] = 1; T.m[2][2] = 0;
		T = matrix_pow(T, n - 3);
		int result = (T.m[0][0] * c + T.m[0][1] * b + T.m[0][2] * a) % MOD;
		std::cout << result << '\n';
	}
}
