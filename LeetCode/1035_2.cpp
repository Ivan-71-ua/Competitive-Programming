#include <bits/stdc++.h>


class Solution {
public:
   int maxUncrossedLines(std::vector<int>& nums1, std::vector<int>& nums2) {
      std::vector<std::vector<int>> dp(nums1.size() + 1, std::vector<int>(nums2.size() + 1));
		for (int i = 0; i < nums1.size(); i++)
		{
			for (int j = 0; j < nums2.size(); j++)
			{
				if(nums1[i] == nums2[j]) {
					dp[i + 1][j + 1] += 1 + dp[i][j];
				}
				else {
					dp[i + 1][j + 1] = std::max(dp[i + 1][j], dp[i][j +1]);
				}
			}
		}
		return dp[nums1.size()][nums2.size()];
	}
};