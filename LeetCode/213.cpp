#include <bits/stdc++.h>

class Solution {
	int max_expencive(int r, int l, std::vector<int>& nums) {
		int prev = 0;
		int cur = 0;
		int next = 0;
		for (int i = r; i < l; i++)
		{
			next = std::max(prev + nums[i], cur);
			prev = cur;
			cur = next;
		}
		return cur;
	}
public:
   int rob(std::vector<int>& nums) {
		return std::max(max_expencive(0, nums.size() - 1, nums), max_expencive(1, nums.size(), nums));
	}
};