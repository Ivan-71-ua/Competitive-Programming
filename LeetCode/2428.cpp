#include <bits/stdc++.h>


class Solution {
	int get_sum_clock(int i, int j, std::vector<std::vector<int>> &pref_sum) {
		int sum = 0;
		sum += pref_sum[i][j + 2] - pref_sum[i][j - 1];
		sum += pref_sum[i + 1][j + 1] - pref_sum[i + 1][j];
		sum += pref_sum[i + 2][j + 2] - pref_sum[i + 2][j - 1];
		return sum;
	}
public:
	int maxSum(std::vector<std::vector<int>>& grid) {
		std::vector<std::vector<int>> pref_sum(grid.size() + 1, std::vector<int>(grid[0].size() +1));
		for (int i = 1; i <= grid.size(); i++)
		{
			for (int j = 1; j <= grid[0].size(); j++)
			{
				pref_sum[i][j] = pref_sum[i][j - 1] + grid[i - 1][j - 1];
			}
		}
		int res = 0;
		for (int i = 0; i < grid.size() - 2; i++)
		{
			for (int j = 0; j < grid[0].size() - 2; j++)
			{
				if(i + 2 < grid.size() && j + 2 < grid[0].size()) {
					res = std::max(res, get_sum_clock(i + 1, j + 1, pref_sum));
				}
			}
		}
		return res;
	}
};