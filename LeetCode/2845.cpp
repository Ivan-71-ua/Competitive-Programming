

#include <bits/stdc++.h>




class Solution {
public:
	long long countInterestingSubarrays(std::vector<int>& nums, int modulo, int k) {
		long long n = nums.size(), ans = 0;
		std::unordered_map<int, int> mp;
		mp[0] = 1;
		long long cnt = 0;
		for (int i = 0; i < n; i++) {
			if(nums[i] % modulo == k) {
				cnt++;
			}
			int rem = (cnt - k + modulo) % modulo;
			ans += mp[rem];
			mp[cnt % modulo]++;
		}
		return ans;
	}
};