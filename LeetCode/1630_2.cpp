#include <bits/stdc++.h>

class Solution {
	bool check_ares(std::vector<int>& nums, int l, int r) {
		int min = INT32_MAX;
		int max = INT32_MIN;
		for (int i = l; i <= r; i++) {
			min = std::min(min, nums[i]);
			max = std::max(max, nums[i]);
		}
		if (min == max)
			return true;
		int n = r - l + 1;
		if ((max - min) % (n - 1) != 0)
			return false;
		int diff = (max - min) / (n - 1);
		std::vector<int> pres(n, 0);
		for (int i = l; i <= r; i++) {
			if ((nums[i] - min) % diff != 0)
				return false;
			int idx = (nums[i] - min) / diff;
			if (pres[idx])
				return false;
			pres[idx] = true;
		}
		return true;
	}
public:
	std::vector<bool> checkArithmeticSubarrays(std::vector<int>& nums, std::vector<int>& l, std::vector<int>& r) {
		std::vector<bool> ans(l.size());
		for (int i = 0; i < l.size(); i++) {
			ans[i] = check_ares(nums, l[i], r[i]);
		}
		return ans;
	}
};
