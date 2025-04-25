#include <bits/stdc++.h>


const int MOD = 998244353;

int main() {
	int N;
	std::cin >> N;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}

	std::vector<int> result(N, 0);

	// Кількість підпослідовностей довжиною 1 дорівнює кількості елементів
	result[0] = N;

	// dp[k][j][d] - number of arithmetic subsequences of length k ending at index j with difference d
	std::vector<std::unordered_map<int, std::unordered_map<int, int>>> dp(N + 1);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			int d = A[i] - A[j];
			for (int k = 1; k <= N; k++) {
					if (dp[k].count(j) && dp[k][j].count(d)) {
						dp[k + 1][i][d] = (dp[k + 1][i][d] + dp[k][j][d]) % MOD;
					}
					//dp[k + 1][i][d] = (dp[k + 1][i][d] + dp[k][j][d]) % MOD;
			}
			dp[2][i][d] = (dp[2][i][d] + 1) % MOD;  // Each pair (A[j], A[i]) forms an arithmetic subsequence of length 2
		}
	}

	for (int i = 1; i < N; i++) {
		for (auto& [d, count_map] : dp[i + 1]) {
			for (auto& [_, count] : count_map) {
				result[i] = (result[i] + count) % MOD;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		std::cout << result[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
