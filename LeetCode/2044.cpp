#include <bits/stdc++.h>


class Solution {
public:
	int countMaxOrSubsets(std::vector<int>& nums) {
		int res = 0;
		int max = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			max |= nums[i];
		}
		std::vector<std::vector<int>> subsets{{}};
		int n = 0;
		int cur = 0;
		while(n < nums.size()) {
			int s_z = subsets.size();
			for (int i = 0; i < s_z; i++) {
				subsets.push_back(subsets[i]);
				subsets.back().push_back(nums[n]);
			}
			for (; cur < subsets.size(); cur++)
			{
				int tmp = 0;
				for (auto now: subsets[cur])
				{
					tmp |= now;
				}
				if(tmp == max)
					res++;
			}
			n++;
		}
		return res;
	}
};