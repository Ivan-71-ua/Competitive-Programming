#include <bits/stdc++.h>

class Solution {
	void update(std::vector<int>& bitCount, int n, int diff) {
		for (int i = 0; i < 32; i++) {
			if (n & (1 << i)) {
				bitCount[i] += diff;
			}
		}
	}

	int bit_to_int(const std::vector<int>& bitCount) {
		int res = 0;
		for (int i = 0; i < 32; i++) {
			if (bitCount[i] > 0) {
				res |= (1 << i);
			}
		}
		return res;
	}

public:
	int minimumSubarrayLength(std::vector<int>& nums, int k) {
		int res = INT32_MAX;
		int l = 0;
		std::vector<int> bitCount(32);

		for (int i = 0; i < nums.size(); i++) {
			update(bitCount, nums[i], 1);
			int cur = bit_to_int(bitCount);

			while (l <= i && cur >= k) {
				res = std::min(res, i - l + 1);
				update(bitCount, nums[l], -1);
				l++;
				cur = bit_to_int(bitCount);
			}
		}

		return (res == INT32_MAX) ? -1 : res;
	}
};
