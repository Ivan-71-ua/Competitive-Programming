#include <bits/stdc++.h>

class Solution {
public:
	int maxTotalReward(std::vector<int>& rewardValues) {
		//std::stable_sort(rewardValues.begin(), rewardValues.end());
		std::vector<std::vector<int>> dp(rewardValues.size(), std::vector<int>(rewardValues.size()));
		int res = -1;
		for (int i = 0; i < rewardValues.size(); i++)
		{
			dp[i][0] = rewardValues[i];
			res = std::max(res, rewardValues[i]);
		}
		//int res = dp[0][0];
		for (int i = 1; i < rewardValues.size(); i++)
		{
			for (int j = 1; j < rewardValues.size(); j++)
			{
				if(dp[i][j-1] < rewardValues[j]) {
					dp[i][j] += rewardValues[j] + dp[i][j -1];
				} else {
					dp[i][j] = dp[i][j - 1];
				}
				res = std::max(res, dp[i][j]);
			}
		}
		return res;
	}
};
