#include <bits/stdc++.h>


class Solution {
public:
	int maximumSum(std::vector<int>& nums) {
		std::vector<std::pair<int, int>> sum_d(100);
		for (int i = 0; i < nums.size(); i++)
		{
			int sum_of_d = 0;
			int tmp = nums[i];
			while(tmp) {
				sum_of_d += tmp % 10;
				tmp /= 10;
			}
			if(sum_d[sum_of_d].first <= nums[i]) {
				sum_d[sum_of_d].second = sum_d[sum_of_d].first;
				sum_d[sum_of_d].first = nums[i];
			} else if(sum_d[sum_of_d].second < nums[i]) {
				sum_d[sum_of_d].second = nums[i];
			}
		}
		int res = -1;
		for(auto [a, b]: sum_d) {
			if(a == 0 || b == 0) continue;
			res = std::max(res, a + b);
		}
		return res;
	}
};



