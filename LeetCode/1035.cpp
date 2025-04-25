#include <bits/stdc++.h>

class Solution {
	int Max_comb(int j, int k, std::vector<int>& nums1, std::vector<int>& nums2, std::vector<std::vector<int>> &dp) {
		if(j == nums1.size() || k == nums2.size()) {
			return 0;
		} 
		if(dp[j][k]) {
			return dp[j][k];
		}
		if(nums1[j] == nums2[k]) {
			dp[j][k] = 1 + Max_comb(j + 1, k + 1, nums1, nums2, dp);
		} else {
			dp[j][k] = std::max(Max_comb(j + 1, k, nums1, nums2, dp), Max_comb(j, k + 1, nums1, nums2, dp));
		}
		return dp[j][k];
	}
public:
   int maxUncrossedLines(std::vector<int>& nums1, std::vector<int>& nums2) {
		std::vector<std::vector<int>> dp(nums1.size() + 1, std::vector<int>(nums2.size() + 1));
		return Max_comb(0, 0, nums1, nums2, dp);
	}
};

int main() {
	Solution ans;
	std::vector<int> ss{1,3,7,1,7,5};
	std::vector<int> dd{1,9,2,5,1};
	ans.maxUncrossedLines(ss, dd);
}