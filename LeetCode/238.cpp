#include <bits/stdc++.h>

class Solution {
public:
   std::vector<int> productExceptSelf(std::vector<int>& nums) {
		std::vector<int> ans(nums.size());
		int res = 1;
		for (int i = 0; i < nums.size(); i++)
		{
			ans[i] = res;
			res *= nums[i];
		}
		res = 1;
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			ans[i] *= res;
			res *= nums[i];
		}
		return ans;
	}
};

int main() {
	Solution ams;
	std::vector<int> nums{1, 2, 3, 4};
	ams.productExceptSelf(nums);
}