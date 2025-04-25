#include <bits/stdc++.h>




class Solution {
public:
	std::vector<bool> isArraySpecial(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
		std::vector<int> bad;
		for (int i = 0; i < nums.size() -1; i++)
		{
			if(!((nums[i] + nums[i + 1]) & 1)) {
				bad.push_back(i);
			} 
		}
		std::vector<bool> ans;
		for (auto &&i : queries)
		{
			int s = i[0], f = i[1];
			int idx = std::lower_bound(bad.begin(), bad.end(), s) - bad.begin();
			if(idx == bad.size()) {
				ans.push_back(true);
			} else {
				int id = bad[idx];
				if(id  < f) {
					ans.push_back(false);
				} else {
					ans.push_back(true);
				}
			}
		}
		return ans;
	}
};


