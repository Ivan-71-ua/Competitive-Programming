#include <bits/stdc++.h>



class Solution {
public:
	int maximumLength(std::vector<int>& nums) {
		int n = nums.size();
		int cnt_odd = 0, cnt_even = 0;
		int even_dp = 0, odd_dp = 0;
		for (int i = 0; i < n; i++) {
			if(nums[i] & 1) {
				cnt_even++;
				even_dp = std::max(even_dp, odd_dp + 1);
			} else {
				cnt_odd++;
				odd_dp = std::max(odd_dp, even_dp + 1);
			}
		}
		return std::max({cnt_even, cnt_odd, even_dp, odd_dp});
	}
};