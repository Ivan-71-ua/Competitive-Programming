#include <bits/stdc++.h>


class Solution {
public:
	int reductionOperations(std::vector<int>& nums) {
		int ans = 0;
		std::stable_sort(nums.begin(), nums.end());
		int min = nums[0];
		for (int i = nums.size() -1; nums[i] != min; i--)
		{
			ans += nums.size() - i;
			while(nums[i - 1] == nums[i]) {
				i--;
			}
		}
		return ans;
	}
};

int mian() {
	Solution ans;
	std::vector<int> ss{1, 1, 2, 2, 3};
	ans.reductionOperations(ss);
}