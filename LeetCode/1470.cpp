
#include <bits/stdc++.h>


class Solution {
public:
	std::vector<int> shuffle(std::vector<int>& nums, int n) {
		std::vector<int> res(n * 2);
		for (int i = 0, idx = 0; i < n; i++) {
			res[idx++] = nums[i];
			res[idx++] = nums[i + n];
		}
		return res;
	}
};