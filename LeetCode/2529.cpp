#include <bits/stdc++.h>



class Solution {
public:
	int maximumCount(std::vector<int>& nums) {
		int f = std::upper_bound(nums.begin(), nums.end(), -1) - nums.begin();
		int s = std::upper_bound(nums.begin(), nums.end(), 0) - nums.begin();
		return std::max(f, (int)nums.size() - s);
	}
};