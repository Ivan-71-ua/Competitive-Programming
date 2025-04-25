#include <bits/stdc++.h>


const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
   std::vector<int> getConcatenation(std::vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			nums.push_back(nums[i]);
		}
		return nums;
	}
};