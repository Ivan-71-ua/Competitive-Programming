#include <bits/stdc++.h>




class Solution {
public:
	std::vector<int> applyOperations(std::vector<int>& nums) {
		for (int i = 0; i < nums.size() - 1; i++) {
			if(nums[i] == nums[i + 1]) {
				nums[i] *= 2;
				nums[i + 1] = 0;
			}
		}
		std::vector<int> res(nums.size());
		int j = 0;
		for (int i = 0; i < nums.size(); i++) {
			if(nums[i] != 0) {
				res[j] = nums[i];
				j++;
			} 
		}
		return res;
	}
};