#include <bits/stdc++.h>


class Solution {
public:
	int maximumUniqueSubarray(std::vector<int>& nums) {
		int res = 0, l = 0, cur_sum = 0;
		std::bitset<10001> cnt;
		for (int r = 0; r < nums.size(); r++) {
			if(cnt[nums[r]]) {
				while(nums[l] != nums[r]) {
					cnt[nums[l]] = 0;
					cur_sum -= nums[l];
					l++;
				}
				l++;
			} else {
				cnt[nums[r]] = 1;
				cur_sum += nums[r];
				res = std::max(res, cur_sum);
			}
		}
		return res;
	}
};