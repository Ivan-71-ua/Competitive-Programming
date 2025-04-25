#include <bits/stdc++.h>


class Solution {
public:
   long long gridGame(std::vector<std::vector<int>>& grid) {
		std::vector<std::vector<long long>> vec( 2 , std::vector<long long> (grid[0].size()));
		for (int i = 0; i < 2; i++)
		{
			long long pref = 0;
			for (int j = 0; j < grid[0].size(); j++)
			{
				pref += grid[i][j];
				vec[i][j] = pref;
			}
		}
		long long sum = vec[0][grid[0].size() - 1] + vec[1][grid[0].size() - 1];
		long long ans = sum;
		for (int i = 0; i < grid[0].size(); i++)
		{
			long long temp1 = 0, temp2 = 0;
			temp1 += vec[0][grid[0].size() - 1] - vec[0][i];
			if(i > 0)
				temp2 += vec[1][i - 1];
			ans = std::min(ans, std::max(temp1, temp2));
		}
		return ans;
	}
};