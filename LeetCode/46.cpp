#include <bits/stdc++.h>


class Solution {
public:
	std::vector<std::vector<int>> permute(std::vector<int>& nums) {
		std::stable_sort(nums.begin(), nums.end());
		std::vector<std::vector<int>> ans;
		do
		{
			ans.push_back(nums);
		} while (std::next_permutation(nums.begin(), nums.end()));
		return ans;
	}
};