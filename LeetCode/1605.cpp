#include <bits/stdc++.h>



class Solution {
public:
	std::vector<std::vector<int>> restoreMatrix(std::vector<int>& rowSum, std::vector<int>& colSum) {
		std::vector<std::vector<int>> ans(rowSum.size(), std::vector<int>(colSum.size()));
		for (int i = 0; i < rowSum.size(); i++)
		{
			for (int j = 0; j < colSum.size(); j++)
			{
				ans[i][j] = std::min(rowSum[i], colSum[j]);
				rowSum[i] -= ans[i][j];
				colSum[j] -= ans[i][j];
			}
		}
		return ans;
	}
};