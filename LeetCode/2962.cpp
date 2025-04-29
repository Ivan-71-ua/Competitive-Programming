
#include <bits/stdc++.h>



class Solution {
public:
	long long countSubarrays(std::vector<int>& nums, int k) {
		int maxs = 0, cnt = 0, n = nums.size(), l = 0;
		for (int i = 0; i < n; i ++) {
			if(nums[i] > maxs) {
				maxs = nums[i];
				cnt = 1;
			} else if(nums[i] == maxs) {
				cnt ++;
			}
		}
		if(cnt < k)
			return 0;
		cnt = 0;
		long long res = 0;
		for (int r = 0; r < n; r++) {
			if(nums[r] == maxs) {
				cnt++;
			}
			while(cnt >= k) {
				if(nums[l] == maxs)
					cnt--;
				l++;
			}
			res += l;
		}
		return res;
	}
};