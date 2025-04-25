#include <bits/stdc++.h>




class Solution {
	int count_one(int n) {
		int res = 0;
		while(n) {
			res += n % 2;
			n /= 2;
		}
		return res;
	}

public:
	bool canSortArray(std::vector<int>& nums) {
		int n = nums.size();
		std::vector<std::pair<int, int>> group;
		group.push_back({nums[0], nums[0]});
		for (int i = 1; i < n; i++)
		{
			int cur = count_one(nums[i]);
			int prev = count_one(nums[i -1]);
			if(cur != prev) {
				group.push_back({nums[i], nums[i]});
			} else {
				group.back().first = std::min(group.back().first, nums[i]);
				group.back().second = std::max(group.back().second, nums[i]);
			}
		}
		for (int i = 1; i < group.size(); i++) {
			if(group[i -1].second > group[i].first)
				return false;
		}
		return true;
	}
};