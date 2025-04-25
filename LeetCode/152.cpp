#include <bits/stdc++.h>

class Solution {
public:
   int maxProduct(std::vector<int>& nums) {
		std::vector<std::pair<int, int>> max_min(nums.size() + 1);
		int res = INT32_MIN;
		max_min[0].first = 1;
		max_min[0].second = 1;
		for (int i = 1; i < max_min.size(); i++) {
			if(nums[i -1] !=  0) {
				max_min[i].first = std::max(nums[i -1], std::max(nums[i-1] * max_min[i -1].first, nums[i-1] * max_min[i-1].second));
				max_min[i].second = std::min(nums[i-1], std::min(nums[i-1] * max_min[i -1].first, nums[i-1] * max_min[i-1].second));
				res = std::max(res, std::max(max_min[i].first, max_min[i].second));
			}
			else {
				res = std::max(res, 0);
				max_min[i].first = 1;
				max_min[i].second = 1;
			}
		}
		return res;
	}
};

int main() {
	Solution ams;
	std::vector<int> ss{-2,3,-4};
	ams.maxProduct(ss);
}