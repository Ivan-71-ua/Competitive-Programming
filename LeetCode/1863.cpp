
#include <bits/stdc++.h>




class Solution {
public:
	int subsetXORSum(std::vector<int>& nums) {
		int sum = 0;
		std::vector<int> mult{0};
		for (int i = 0; i < nums.size(); i++) {
			int cur_s = mult.size();
			for (int j = 0; j < cur_s; j++) {
				sum += mult[j] ^ nums[i];
				mult.push_back(mult[j] ^ nums[i]);
			}
		}
		return sum;
	}
};