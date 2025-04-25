#include <bits/stdc++.h>

class Solution {
public:
   int rob(std::vector<int>& nums) {
		if(nums.size() == 1)
			return nums[0];
		if(nums.size() == 2)
			return std::max(nums[0], nums[1]);
		std::vector<int> max_prise(nums.size());
		max_prise[0] = nums[0];
		max_prise[1] = nums[1];
		max_prise[2] = nums[2] + max_prise[0];
		for (int i = 3; i < nums.size(); i++)
		{
			max_prise[i] = nums[i] + std::max(max_prise[i - 2], max_prise[i - 3]);
		}
		return std::max(max_prise[max_prise.size() -1],max_prise[max_prise.size() - 2]);
	}
};

int main() {
	Solution ans;
	std::vector<int> ss{2, 7, 9, 3, 1};
	ans.rob(ss);
}