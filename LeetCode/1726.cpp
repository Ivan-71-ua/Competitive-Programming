#include <bits/stdc++.h>


class Solution {
public:
	int tupleSameProduct(std::vector<int>& nums) {
		int n = nums.size();
		std::unordered_map<int, int> doub;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				doub[nums[i] * nums[j]]++;
			}
		}
		int res = 0;
		for (auto &k: doub) {
			if(k.second > 1)
				res += k.second * (k.second -1) * 4;
		}
		return res;
	}
};