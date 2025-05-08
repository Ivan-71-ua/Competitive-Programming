#include <bits/stdc++.h>




class Solution {
	int dx [4] = {0, 0, -1, 1};
	int dy[4] = {-1, 1, 0, 0};
public:
	int minTimeToReach(std::vector<std::vector<int>>& moveTime) {
        std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);      
      std::cout.tie(nullptr);
		int n = moveTime.size(), m = moveTime[0].size();
		std::vector<std::vector<int>> dp(n, std::vector<int>(m, INT_MAX));
		dp[0][0] = 0;
		std::priority_queue<std::tuple<int, int, int, int>, std::vector<std::tuple<int, int, int, int>>, std::greater<>> pq;
		pq.push({0, 0, 0, 1});
		while(!pq.empty()) {
			auto [t, x, y, step] = pq.top();
			pq.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				int tmp_t = t < moveTime[nx][ny] ? moveTime[nx][ny] : t;
				if(dp[nx][ny] > tmp_t + step) {
					dp[nx][ny] = tmp_t + step;
					if(step == 1) {
						pq.push({tmp_t + step, nx, ny, 2});
					} else {
						pq.push({tmp_t + step, nx, ny, 1});
					}
				}
			}
		}
		return dp[n -1][ m - 1];
	}
};