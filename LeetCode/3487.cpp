
#include <bits/stdc++.h>

class Solution {
public:
	int maxSum(std::vector<int>& nums) {
		int sum_pos = 0, min_neg = -300;
		std::vector<int> cnt(202);
		for(auto n: nums) {
			if(!cnt[n + 100]) {
				if(n > 0) {
					sum_pos += n;
				} else {
					min_neg = std::max(min_neg, n);
				}
			}
			cnt[n + 100]++;
		}
		if(sum_pos) {
			return sum_pos;
		}
		return min_neg;
	}
};