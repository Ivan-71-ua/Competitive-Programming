
#include <bits/stdc++.h>


class Solution {
public:
	bool isZeroArray(std::vector<int>& nums, std::vector<std:: vector<int>>& queries) {
		int n = nums.size();
		std::vector<int> prefixSum(n + 1, 0);
		for (int i = 0; i < queries.size(); i++) {
			int l = queries[i][0], r = queries[i][1];
			prefixSum[l]--;
			prefixSum[r + 1]++;
		}
		for (int i = 1; i <= n; i++) {
			prefixSum[i] += prefixSum[i - 1];
		}
		bool isZero = true;
		for (int i = 0; i < n; i++) {
			nums[i] = std::max(0, nums[i] + prefixSum[i]);
			if (nums[i] != 0) {
				isZero = false;
				break;
			}
		}
		return isZero;
	}
};