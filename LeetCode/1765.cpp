
#include <bits/stdc++.h>



class Solution {
	std::vector<int> xs{1, -1, 0, 0};
	std::vector<int> ys{0, 0, -1, 1};
public:
	std::vector<std::vector<int>> highestPeak(std::vector<std::vector<int>>& isWater) {
		int n = isWater.size(), m = isWater[0].size();
		std::queue<std::pair<int, int>> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(isWater[i][j] == 1) {
					q.push({i, j});
					isWater[i][j] = 0;
				} else {
					isWater[i][j] = -1;
				}
			}
		}
		while (!q.empty())
		{
			auto [x, y] = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int cx = x + xs[i], cy = y + ys[i];
				if(cx < 0 || cy < 0 || cx >= n || cy >= m || isWater[cx][cy] != -1) {
					continue;
				}
				isWater[cx][cy] = isWater[x][y] + 1;
				q.push({cx, cy});
			}
		}
		return isWater;
	}
};

int main() {
	std::vector<std::vector<int>> q{{0, 1}, {0, 0}};
	Solution asn;
	asn.highestPeak(q);
}