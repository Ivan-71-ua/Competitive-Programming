#include <bits/stdc++.h>
#define int long long


int32_t main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> way(n, std::vector<int>(m));
	std::vector<std::vector<int>> dp(n, std::vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cin >> way[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = m -1; j >= 0; j--)
		{
			dp[i][j] = way[i][j] + std::max(i - 1 > -1 ? dp[i - 1][j] : 0, j +1 < m ? dp[i][j+1] : 0);
		}
	}
	std::cout << dp[n - 1][0];
}