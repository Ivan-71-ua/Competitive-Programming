
#include <bits/stdc++.h>




class Solution {
public:
	long long countBadPairs(std::vector<int>& nums) {
		long long n = nums.size();
		long long all = (n * (n - 1)) / 2;
		std::unordered_map<int, int> bad_pair;
		for (int i = 0; i < n; i++) {
			all += i - bad_pair[i - nums[i]];
			bad_pair[i - nums[i]]++;
		}
		return all;
	}
};