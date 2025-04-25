
#include <bits/stdc++.h>


class Solution {
public:
	int minimumObstacles(std::vector<std::vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		std::vector<std::vector<int>> dp(n, std::vector<int>(m, INT32_MAX));
		std::deque<std::pair<int, int>> q;
   	dp[0][0] = 0;
		std::vector<int> xs{1, -1, 0, 0};
		std::vector<int> ys{0, 0, 1, -1};
		q.push_front({0, 0});
		while(!q.empty()) {
			auto [x, y] = q.front();
			q.pop_front();
			for (int i = 0; i < 4; i++)
			{
				int nx = x + xs[i];
				int ny = y + ys[i];
				if(nx < n && nx > -1 && ny < m && ny > -1) {
					int new_weight = dp[x][y] + grid[nx][ny];
					if(new_weight < dp[nx][ny]) {
						dp[nx][ny] = new_weight;
						if(grid[nx][ny]) {
							q.push_back({nx, ny});
						} else {
							q.push_front({nx, ny});
						}
					}
				}
			}
		}
		return dp[n - 1][m - 1];
	}
};