#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define ll long long


int sumRegion(int row1, int col1, int row2, int col2, std::vector<std::vector<int>>& sum_p) {
	return sum_p[row2 + 1][col2 + 1] - sum_p[(row1 + 1) - 1][col2 + 1] - (sum_p[row2 + 1][(col1 + 1) - 1] - sum_p[(row1 + 1) - 1][(col1 + 1) - 1]);
}

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> tp(n, std::vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cin >> tp[i][j];
		}
	}
	std::vector<std::vector<int>> sum_p (n + 2, std::vector<int>(m + 2, 0));
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < m; j++)
		{
			sum += tp[i][j];
			sum_p[i + 1][j + 1] = sum;
			sum_p[i + 1][j + 1] += sum_p[(i + 1) - 1][j + 1];
		}
	}
	int q;
	std::cin >> q;
	for (int i = 0; i < q; i++)
	{
		int x, y, x1, y1;
		std::cin >> x >> y >> x1 >> y1;
		std::cout << sumRegion(x -1, y -1, x1 -1, y1 -1, sum_p) << '\n';
	}
	
}