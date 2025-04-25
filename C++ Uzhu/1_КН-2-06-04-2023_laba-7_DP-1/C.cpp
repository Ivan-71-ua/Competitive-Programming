#include <bits/stdc++.h>
#define int long long

int32_t main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> tmp(n, std::vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cin >> tmp[i][j];
		}
	}
	for (int i = 1; i < n; i++)
	{
		tmp[i][0] = tmp[i][0] + tmp[i - 1][0];
	}
	for (int i = 1; i < m; i++)
	{
		tmp[0][i] = tmp[0][i] + tmp[0][i -1];
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			tmp[i][j] = tmp[i][j] + std::min(tmp[i - 1][j], tmp[i][j - 1]);
		}
	}
	std::cout << tmp[n - 1][m - 1];
}