
#include <bits/stdc++.h>



class Solution {
	std::vector<int> xs{1, -1, 0, 0};
	std::vector<int> ys{0, 0, 1, -1};

public:
	int trapRainWater(std::vector<std::vector<int>>& heightMap) {
		int n = heightMap.size(), m = heightMap[0].size();
		std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, std::greater<>> q;
		int res = 0;
		int max_h = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(i == 0 || i == n -1 || j == 0 || j == m - 1) {
					q.push({heightMap[i][j], {i, j}});
					heightMap[i][j] = -1;
				}
			}
		}
		while (!q.empty()) 
		{
			int cur_h = q.top().first;
			max_h = std::max(max_h, cur_h);
			res += max_h - cur_h;
			auto [x, y] = q.top().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int cx = x + xs[i], cy = y + ys[i];
				if(cx < 0 || cy < 0 || cx == n || cy == m ||heightMap[cx][cy] == -1) continue;
				q.push({heightMap[cx][cy], {cx, cy}});
				heightMap[cx][cy] = -1;
			}
		}
		return res;
	}
};