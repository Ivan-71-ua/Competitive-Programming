#include <bits/stdc++.h>

int main() {
	int n;
	long long res = 0;
	std::cin >> n;
	std::vector<int> p(n), dp(n);
	for (int i = 0; i < n; i++) {
		std::cin >> p[i];
	}
	// Вычисление dpi = max(pi, …, pn-1)
	dp[n - 1] = p[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		dp[i] = std::max(p[i], dp[i + 1]);
	}
	// Вычисление общей прибыли
	for (int i = 0; i < n; i++) {
		res += dp[i] - p[i];
	}
	std::cout << res << std::endl;
}


int main() {
	int n;
	long long res = 0;
	std::cin >> n;
	std::vector<int> p(n), dp(n);
	for (int i = 0; i < n; i++) {
		std::cin >> p[i];
	}
	// Вычисление dpi = max(pi, …, pn-1)
	dp[n - 1] = p[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		dp[i] = std::max(p[i], dp[i + 1]);
	}
	// Вычисление общей прибыли
	for (int i = 0; i < n; i++) {
		res += dp[i] - p[i];
	}
	std::cout << res << std::endl;
}
