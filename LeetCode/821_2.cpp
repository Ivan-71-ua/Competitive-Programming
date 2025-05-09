#include <bits/stdc++.h>


class Solution {
public:
	std::vector<int> shortestToChar(std::string s, char c) {
		int n = s.size();
	std::vector<int> dp(n, INT32_MAX);  // конечно проще было бы использовать long long, тогда была бы более честная "бесконечность", но алгоритм линейный, поэтому long long сожрал бы всю память.
	// Заполняем базу динамики
	for (int i = 0; i < n; ++i) {
		if (s[i] == c) {
			dp[i] = 0;
		}
	}
	// Идея такая, что нам достаточно пройтись по дпшке два раза: в одну и другую сторону.
	// Притом при прямом проходе у нас посчитается минимальное расстояние символов 'c', которые находятся левее текущего символа
	// а при обратном проходе ещё учтётся минимальное расстояние до символов 'c', которые находятся правее текущего символа
	for (int i = 1; i < n; ++i) {
		if (dp[i - 1] == INT32_MAX) {
				continue;
		}
		dp[i] = std::min(dp[i], dp[i - 1] + 1);
	}
	for (int i = n - 2; i >= 0; --i) {
		if (dp[i + 1] == INT32_MAX) {
				continue;
		}
		dp[i] = std::min(dp[i], dp[i + 1] + 1);
	}
	return dp;
	}
};