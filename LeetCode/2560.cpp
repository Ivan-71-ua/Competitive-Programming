
#include <bits/stdc++.h>





class Solution {
	bool can(int cur_max, int k, std::vector<int>& nums) {
		int cnt = 0;
		for (int i = 0; i < nums.size(); ) {
			if(nums[i] <= cur_max) {
				i += 2;
				cnt++;
			} else {
				i++;
			}
			if(cnt == k)
				break;
		}
		return cnt == k;
	}
public:
	int minCapability(std::vector<int>& nums, int k) {
		auto [a, b] = std::minmax_element(nums.begin(), nums.end());
		int l = *a, r = *b;
		while(l <=r) {
			int mid = (r - l) / 2 + l;
			if(can(mid, k, nums)) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return l;
	}
};