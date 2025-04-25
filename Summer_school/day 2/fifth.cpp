#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long
const int MOD = 1000000007;

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

void build_transition_matrix(Matrix &T, int m, const std::vector<std::pair<int, int>> &forbidden) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			T[i][j] = 1;
		}
	}
	for (int i = 0; i < forbidden.size(); i++) {
		T[forbidden[i].first][forbidden[i].second] = 0;
	}
}

int32_t main() {
	fast
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<std::pair<int, int>> forbidden(k);
	for (int i = 0; i < k; i++) {
		std::string s;
		std::cin >> s;
		int u = (islower(s[0]) ? s[0] - 'a' : s[0] - 'A' + 26);
		int v = (islower(s[1]) ? s[1] - 'a' : s[1] - 'A' + 26);
		forbidden[i] = {u, v};
	}
	Matrix T(m);
	build_transition_matrix(T, m, forbidden);
	Matrix result = T.pow(n - 1);
	int total_sequences = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			total_sequences = (total_sequences + result[i][j]) % MOD;
		}
	}
	std::cout << total_sequences << '\n';
}
