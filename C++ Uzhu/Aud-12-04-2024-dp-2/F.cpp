#include <bits/stdc++.h>
#define int long long


int32_t main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 1));
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= m; j++)
		{
			dp[i][j] = dp[i -1][j] + dp[i][j-1];
		}
	}
	std::cout << dp[n][m];
}