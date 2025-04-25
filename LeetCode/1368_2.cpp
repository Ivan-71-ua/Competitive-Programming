#include <bits/stdc++.h>



class Solution {
	std::vector<int> xs{ -1, 0, 0, 1, -1};
	std::vector<int> ys{-1, 1, -1, 0, 0};
public:
	int minCost(std::vector<std::vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, std::greater<>> q;
		std::vector<std::vector<int>> dp(n, std::vector<int>(m, INT32_MAX));
		dp[0][0] = 0;
		q.push({0, {0, 0}});
		while(!q.empty()) {
			auto [x, y] = q.top().second;
			int weight = q.top().first;
			q.pop();

			if(x == n -1 && y == m - 1) {
				return dp[n - 1][m - 1];
			}

			for (int i = 1; i <= 4; i++) {
				int cx = x + xs[i], cy = y + ys[i];
				int c_w = weight;
				if(cx >= n || cy >= m || cx < 0 || cy < 0) continue;
				
				if(grid[x][y] != i) {
					c_w++;
				}
				if(c_w < dp[cx][cy]) {
					dp[cx][cy] = c_w;
					q.push({c_w, {cx, cy}});
				}
			}
		}
		return -1;
	}
};