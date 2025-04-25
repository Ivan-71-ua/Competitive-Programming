#include <bits/stdc++.h>




class Solution {
	std::vector<int> xs{1, -1, 0, 0}, ys{0, 0, -1, 1};
	void dfs(int x, int y, std::vector<std::vector<int>>& grid, int &cur) {
		if(x < 0 || y < 0 || x == grid.size() || y == grid[0].size() || grid[x][y] == 0)
			return;
		cur += grid[x][y];
		grid[x][y] = 0;
		for (int i = 0; i < 4; i++) {
			dfs(x + xs[i], y + ys[i], grid, cur);
		}
	}
public:
	int findMaxFish(std::vector<std::vector<int>>& grid) {
		int res = 0;
		int n = grid.size(), m = grid[0].size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(grid[i][j] != 0) {
					int cur = 0;
					dfs(i, j, grid, cur);
					res = std::max(res, cur);
				}
			}
		}
		return res;
	}
};