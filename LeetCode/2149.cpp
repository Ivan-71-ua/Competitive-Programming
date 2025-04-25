#include <bits/stdc++.h>


class Solution {
public:
	std::vector<int> rearrangeArray(std::vector<int>& nums) {
		std::vector<int> positive;
		std::vector<int> negative;
		for (int i = 0; i < nums.size(); i++)
		{
			if(nums[i] > 0) {
				positive.push_back(nums[i]);
			} else {
				negative.push_back(nums[i]);
			}
		}
		std::vector<int> res(nums.size());
		int id = 0;
		while(id * 2 < nums.size()) {
			res[id * 2] = positive[id];
			res[id * 2 + 1] = negative[id];
			id++;
		}
		return res;
	}
};