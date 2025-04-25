#include <bits/stdc++.h>




class Solution {
public:
	std::vector<int> lexicographicallySmallestArray(std::vector<int>& nums, int limit) {
		std::vector<std::deque<int>> group;
		std::unordered_map<int, int> nums_id;
		std::vector<int> nums2(nums.begin(), nums.end());
		std::sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			if(group.empty() || abs(group.back().back() - nums[i]) > limit) {
				group.push_back({});
			}
			group.back().push_back(nums[i]);
			nums_id[nums[i]] = group.size() - 1;
		}
		std::vector<int> res;
		for (int i = 0; i < nums.size(); i++) {
			int j = nums_id[nums2[i]];
			res.push_back(group[j].front());
			group[j].pop_front();
		}
		return res;
	}
};