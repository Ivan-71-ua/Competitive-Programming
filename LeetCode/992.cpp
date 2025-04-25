
#include <bits/stdc++.h>


class Solution {
public:
	int subarraysWithKDistinct(std::vector<int>& nums, int k) {
		int n = nums.size();
		int l = 0, ln = 0;
		int res = 0;
		std::unordered_map<int, int> unic;
		for (int r = 0; r < n; r++) {
			unic[nums[r]]++;
			while(unic.size()  > k) {
				unic[nums[ln]]--;
				if(unic[nums[ln]] == 0) {
					unic.erase(nums[ln]);
				}
				ln++;
				l = ln;
			}
			while(unic[nums[ln]] > 1) {
				unic[nums[ln]]--;
				ln++;
			}
			if(unic.size() == k) {
				res += ln - l + 1;
			}
		}
		return res;
	}
};