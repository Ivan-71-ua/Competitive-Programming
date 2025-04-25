#include <bits/stdc++.h>
#define int long long


int32_t main() {
	int n, m;
	std::cin >> n;
	std::vector<int> x(n + 3);
	for (int i = 1; i <= n; i++)
		std::cin >> x[i];
	std::cin >> m;
	std::vector<int> y(m + 3);
	for (int i = 1; i <= m; i++)
		std::cin >> y[i];
	std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (x[i] == y[j])
					dp[i][j] = dp[i - 1][j - 1] + 1;
			else
					dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	std::cout << dp[n][m];
}
