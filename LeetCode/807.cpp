#include <bits/stdc++.h>


class Solution {
public:
	int maxIncreaseKeepingSkyline(std::vector<std::vector<int>>& grid) {
		std::vector<int> max_in_row(grid.size());
		std::vector<int> max_in_col(grid.size());
		for (int i = 0; i < grid.size(); i++)
		{
				for (int j = 0; j < grid.size(); j++)
				{
					max_in_row[i] = std::max(max_in_row[i], grid[i][j]);
					max_in_col[i] = std::max(max_in_col[i], grid[j][i]);
				}
		}
		int ans = 0;
		for (int i = 0; i < grid.size(); i++)
		{
				for (int j = 0; j < grid.size(); j++)
				{
					ans += std::min(max_in_col[j], max_in_row[i]) - grid[i][j] ;
				}
		}
		return ans;
	}
};