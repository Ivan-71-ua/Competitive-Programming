#include <bits/stdc++.h>

//BRUTE
class Solution {
	std::vector<int> xs{ -1, 0, 0, 1, -1};
	std::vector<int> ys{-1, 1, -1, 0, 0};
	void dfs(int x, int y, int cur_w, std::vector<std::vector<int>>& grid, int &res, int n , int m) {
			if(x >= n || y >= m || x < 0 || y < 0 || grid[x][y] == -1) return;
			if(x == n -1 && y == m - 1) {
				res = std::min(res, cur_w);
				return;
			}
			int cur = grid[x][y];
			grid[x][y] = -1;
			for (int i = 1; i <= 4; i++) {
				if(cur == i) {
					dfs(x + xs[i], y + ys[i], cur_w, grid, res, n, m);
				} else {
					dfs(x + xs[i], y + ys[i], cur_w + 1, grid, res, n, m);
				}
			}
			grid[x][y] = cur;
	}
public:
	int minCost(std::vector<std::vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		int res = INT32_MAX;
		dfs(0, 0, 0, grid, res, n, m);
		return res;
	}
};