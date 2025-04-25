



#include <bits/stdc++.h>

class Solution {
public:
	int equalPairs(std::vector<std::vector<int>>& grid) {
		std::unordered_map<std::string, std::pair<int, int>> mp;
		int n = grid.size(), m = grid[0].size();
		for (int i = 0; i < n; i++) {
			std::string s = "";
			for (int j = 0; j < m; j++) {
				s += std::to_string(grid[i][j]) + "@";
			}
			mp[s].first++;
		}
		for (int j = 0; j < m; j++) {
			std::string s = "";
			for (int i = 0; i < n; i++) {
				s += std::to_string(grid[i][j]) + "@";
			}
			mp[s].second++;
		}
		int ans = 0;
		for( auto &v: mp) {
			ans += v.second.first * v.second.second;
		}
		return ans;
	}
};
