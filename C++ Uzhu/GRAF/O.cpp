#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long

int32_t main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> matrx(n, std::vector<int>(n));
	for (int i = 0; i < m; i++)
	{
		int a, b;
		std::cin >> a >> b;
		matrx[a - 1][b - 1] = 1;
		matrx[b - 1][a - 1] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << matrx[i][j] << ' ';
		}
		std::cout << '\n';
	}
	
}