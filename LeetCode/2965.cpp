
#include <bits/stdc++.h>




class Solution {
public:
	std::vector<int> findMissingAndRepeatedValues(std::vector<std::vector<int>>& grid) {
		std::vector<int> ans{0, 0};
		int n = grid.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int tmp = abs(grid[i][j]) - 1;
				int id = tmp / n, jd = tmp % n;
				if(grid[id][jd] < 0) {
					ans[0] = tmp + 1;
				} else grid[id][jd] *= -1;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if(grid[i][j] > 0) {
					ans[1] = i * n + j + 1;
				}
			}
		}
		return ans;
	}
};