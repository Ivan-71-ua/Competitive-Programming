#include <bits/stdc++.h>


class Solution {
	void dfs(int x, int y, int n, std::vector<std::vector<int>> &big) {
		if(x < 0 || y < 0 || x >= n || y >= n || big[x][y])
			return;
		big[x][y] = 1;
		dfs(x + 1, y, n, big);
		dfs(x - 1, y, n, big);
		dfs(x, y + 1, n, big);
		dfs(x, y - 1, n, big);
	}
public:
	int regionsBySlashes(std::vector<std::string>& grid) {
		int n = grid.size();
		std::vector<std::vector<int>> big(n * 3, std::vector<int>(n  * 3, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if(grid[i][j] == '/') {
					big[i * 3][j * 3 + 2] = 1;
					big[i * 3 + 1][j * 3 + 1] = 1;
					big[i * 3 + 2][j * 3] = 1;
				} else if(grid[i][j] == '\\') {
					big[i * 3][j * 3] = 1;
					big[i * 3 + 1][j * 3 + 1] = 1;
					big[i * 3 + 2][j * 3 + 2] = 1;
				}
			}
		}
		int res = 0;
		n *= 3;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if(!big[i][j]) {
					res++;
					dfs(i, j, n, big);
				}
			}
		}
		return res;
	}
};