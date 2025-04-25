#include <bits/stdc++.h>




class Solution {
public:
	int countServers(std::vector<std::vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		std::vector<int> xs(n), ys(m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(grid[i][j]) {
					xs[i]++;
					ys[j]++;
				}
			}
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(grid[i][j] && xs[i] + ys[j] > 2) {
					res++;
				}
			}
		}
		return res;
	}
};