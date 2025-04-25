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

std::vector<int> multiply_matrix_vector(const Matrix &matrix, const std::vector<int> &vec) {
	int size = matrix.size;
	std::vector<int> result(size, 0);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			result[i] = (result[i] + matrix.mat[i][j] * vec[j]) % MOD;
		}
	}
	return result;
}

int32_t main() {
	fast
	int n, sx, sy, dx, dy, t;
	std::cin >> n >> sx >> sy >> dx >> dy >> t;

	Matrix base(6);
	base[0][0] = 2; base[0][1] = 1; base[0][2] = 1; base[0][3] = 1; base[0][4] = 0; base[0][5] = 0;
	base[1][0] = 1; base[1][1] = 2; base[1][2] = 1; base[1][3] = 1; base[1][4] = 0; base[1][5] = 0;
	base[2][0] = 1; base[2][1] = 0; base[2][2] = 1; base[2][3] = 0; base[2][4] = 0; base[2][5] = 0;
	base[3][0] = 0; base[3][1] = 1; base[3][2] = 0; base[3][3] = 1; base[3][4] = 0; base[3][5] = 0;
	base[4][0] = 0; base[4][1] = 0; base[4][2] = 1; base[4][3] = 1; base[4][4] = 1; base[4][5] = 0;
	base[5][0] = 0; base[5][1] = 0; base[5][2] = 2; base[5][3] = 2; base[5][4] = 1; base[5][5] = 1;

	Matrix result = base.pow(t);
	std::vector<int> state = {sx, sy, dx, dy, t, 1};
	std::vector<int> final_state = multiply_matrix_vector(result, state);
	int final_x = (final_state[0] % n + n) % n;
	int final_y = (final_state[1] % n + n) % n;

	if (final_x == 0) final_x = n;
	if (final_y == 0) final_y = n;
	std::cout << final_x << " " << final_y << '\n';
}
