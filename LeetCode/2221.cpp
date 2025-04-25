#include <bits/stdc++.h>




class Solution {
public:
	int triangularSum(std::vector<int>& nums) {
		std::vector<int> ans(nums.begin(), nums.end());
		while(ans.size() != 1) {
			std::vector<int> tmp;
			for (int i = 1; i < ans.size(); i++)
			{
				tmp.push_back((ans[i - 1] + ans[i]) % 10);
			}
			ans = tmp;
		}
		return ans[0];
	}
};