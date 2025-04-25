#include <bits/stdc++.h>

class Solution {
public:
   int maxProduct(std::vector<int>& nums) {
		int res = INT32_MIN;
		int Max = 1;
		int Min = 1;
		for (int i = 0; i < nums.size(); i++)
		{
			if(nums[i] != 0) {
				int tp = Max;
				Max = std::max(nums[i], std::max(nums[i] * Max, nums[i] * Min));
				Min = std::min(nums[i], std::min(nums[i] * tp, nums[i] * Min));
				res = std::max(res, std::max(Max, Min));
			} else {
				Max = Min = 1;
				res = std::max(res, 0);
			}
		}
		return res;
	}
};

int main() {
	Solution ams;
	std::vector<int> ss{-4,-3,-2};
	ams.maxProduct(ss);
}