#include <bits/stdc++.h>


class Solution {
public:
	long long countSubarrays(std::vector<int>& nums, long long k) {
		int n = nums.size(), l = 0;
		long long res = 0, sum = 0;
		for (int r = 0; r < n; r++) {
			sum += nums[r];
			while (sum * (r - l + 1) > k) {
				sum -= nums[l++];
			}
			res += r - l + 1;
		}
		return res;
	}
};