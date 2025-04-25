#include <bits/stdc++.h>

class Solution {
public:
	std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
		std::vector<std::vector<int>> ans {{}};
		int n = 0;
		while(n < nums.size()) {
			int s_z = ans.size();
			for (int i = 0; i < s_z; i++)
			{
				ans.push_back(ans[i]);
				ans.back().push_back(nums[n]);
			}
			n++;
		}
		return ans;
	}
};