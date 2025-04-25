#include <bits/stdc++.h>

class Solution {
public:
	long long maximumScore(std::vector<std::vector<int>>& grid) {
		const int MAX_SIZE = 109; // Максимальний розмір сітки з додатковим місцем
		const long long INF = LLONG_MAX; // Представляє нескінченність для порівняння

		std::vector<std::vector<long long>> dp(MAX_SIZE, std::vector<long long>(MAX_SIZE, -INF)); // DP-таблиця для зберігання проміжних результатів
		std::vector<std::vector<long long>> maxPrefix(MAX_SIZE, std::vector<long long>(MAX_SIZE, 0)); // Зберігає макс. префіксні суми
		std::vector<std::vector<long long>> maxSuffix(MAX_SIZE, std::vector<long long>(MAX_SIZE, 0)); // Зберігає макс. суфіксні суми
		std::vector<long long> prefixSum(MAX_SIZE, 0); // Префіксні суми для колонок

		int n = grid.size();

		// Ініціалізація DP-таблиці
		for (int i = 0; i <= n; i++) {
			dp[i][0] = 0; // Базовий випадок
		}
		// Обробка кожної колонки сітки
		for (int col = 0; col < n; col++) {
			// Обчислення префіксних сум для поточної колонки
			for (int row = 1; row <= n; row++) {
				prefixSum[row] = prefixSum[row - 1] + grid[row - 1][col];
			}
			// Ініціалізація maxPrefix та maxSuffix для поточної колонки
			for (int row = 0; row <= n; row++) {
				maxPrefix[row][0] = dp[row][0];
				for (int k = 1; k <= n; k++) {
					maxPrefix[row][k] = std::max(maxPrefix[row][k - 1], dp[row][k]);
				}
				maxSuffix[row][n + 1] = 0;
				for (int k = n; k >= 0; k--) {
					maxSuffix[row][k] = std::max(maxSuffix[row][k + 1], dp[row][k] + (row < k ? prefixSum[k] - prefixSum[row] : 0));
				}
			}
			// Оновлення DP-таблиці на основі поточної колонки
			for (int row = 0; row <= n; row++) {
				for (int k = 0; k <= n; k++) {
					dp[row][k] = std::max(maxPrefix[k][row] + (k < row ? prefixSum[row] - prefixSum[k] : 0), maxSuffix[k][row + 1]);
				}
			}
		}

		// Знаходження максимального значення в DP-таблиці
		long long maxScore = -INF;
		for (int i = 0; i <= n; i++) {
			maxScore = std::max(maxScore, dp[0][i]);
		}

		return maxScore;
	}
};
