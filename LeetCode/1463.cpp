#include <bits/stdc++.h>

class Solution {
	std::vector<int> way{-1, 0, 1};
	int dfs(int r, int c1, int c2, std::vector<std::vector<int>>& grid, std::vector<std::vector<std::vector<int>>>& cash, int n, int m) {
		if (c1 < 0 || c2 < 0 || c1 >= m || c2 >= m || c1 == c2) {
			return 0;
		}
		if (cash[r][c1][c2] != -1) {
			return cash[r][c1][c2];
		}
		if (r == n - 1) {
			return grid[r][c1] + grid[r][c2];
		}
		int res = 0;
		for (auto rob1 : way) {
			for (auto rob2 : way) {
				res = std::max(res, dfs(r + 1, c1 + rob1, c2 + rob2, grid, cash, n, m));
			}
		}
		cash[r][c1][c2] = res + grid[r][c1] + grid[r][c2];
		return cash[r][c1][c2];
	}
public:
	int cherryPickup(std::vector<std::vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		std::vector<std::vector<std::vector<int>>> cash(n, std::vector<std::vector<int>>(m, std::vector<int>(m, -1)));
		return dfs(0, 0, m - 1, grid, cash, n, m);
	}
};
