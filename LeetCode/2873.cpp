
#include <bits/stdc++.h>



class Solution {
public:
	long long maximumTripletValue(std::vector<int>& nums) {
		long long res = 0, n = nums.size();
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					res = std::max({1LL * 0 , res, (long long)(nums[i] - nums[j]) * nums[k]});
				}
			}
		}
		return res;
	}
};