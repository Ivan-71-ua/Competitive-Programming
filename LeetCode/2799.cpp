#include <bits/stdc++.h>



class Solution {
public:
	int countCompleteSubarrays(std::vector<int>& nums) {
		std::unordered_set<int> uniq(nums.begin(), nums.end());
		int n = nums.size(), uniqs = uniq.size(), ans = 0;
		std::vector<int> freq(2001, 0);
		int l = 0, r = 0;
		while(r < n) {
			freq[nums[r]]++;
			if(freq[nums[r]] == 1)
				uniqs--;
			while(uniqs == 0) {
				ans = n - r;
				freq[nums[l]]--;
				if(freq[nums[l]] == 0)
					uniqs++;
				l++;
			}
			r++;
		}
		return ans;
	}
};