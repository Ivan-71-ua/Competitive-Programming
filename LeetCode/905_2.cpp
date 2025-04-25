

#include <bits/stdc++.h>

class Solution {
public:
	std::vector<int> sortArrayByParity(std::vector<int>& nums) {
		int r = 0;
		int l = nums.size() - 1;
		while(true) {
			while(r < l && nums[r] % 2 == 0) {
				r++;
			}
			while(r < l && nums[l] % 2 != 0) {
				l--;
			}
			if(r < l) {
				std::swap(nums[r], nums[l]);
				r++;
				l--;
			} else {
				break;
			}
		}
		return nums;
	}
};