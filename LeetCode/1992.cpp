#include <bits/stdc++.h>



class Solution {
	void dfs(int x, int y, std::vector<std::vector<int>>& land, int &finish_x, int &finish_y) {
		finish_x = std::max(x, finish_x);
		finish_y = std::max(y, finish_y);
		land[x][y] = 0;
		if(x + 1 < land.size() && land[x + 1][y]) {
			dfs(x + 1, y, land, finish_x, finish_y);
		}
		if(y + 1 < land[0].size() && land[x][y +1]) {
			dfs(x, y + 1, land, finish_x, finish_y);
		}
	}
public:
	std::vector<std::vector<int>> findFarmland(std::vector<std::vector<int>>& land) {
		std::vector<std::vector<int>> ans;
		int n = land.size();
		int m = land[0].size();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) {
				if(land[i][j]) {
					ans.push_back({i, j});
					int x = -1;
					int y = -1;
					dfs(i, j, land, x, y);
					ans.back().push_back(x);
					ans.back().push_back(y);
				}
			}
		}
		return ans;
	}
};


int main() {
	Solution ans;
	std::vector<std::vector<int>> res{{1, 0, 0}, {0, 1, 1}, {0, 1, 1}};
	ans.findFarmland(res);
}