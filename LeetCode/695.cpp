#include <bits/stdc++.h>

class Solution {
	int ans = 0;
	void dfs(int x, int y, int &square, std::vector<std::vector<int>>& grid) {
		if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || !grid[x][y]) {
			return;
		}
		grid[x][y] = 0;
		square++;
		dfs(x + 1, y, square, grid);
		dfs(x - 1, y, square, grid);
		dfs(x, y + 1, square, grid);
		dfs(x, y - 1, square, grid);
	}
public:
	int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if(grid[i][j]) {
					int square = 0;
					dfs(i, j, square, grid);
					ans = std::max(ans, square);
				}
			}
		}
		return ans;
	}
};