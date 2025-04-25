#include <bits/stdc++.h>



class Solution {
public:
	long long minimumOperations(std::vector<int>& nums, std::vector<int>& target) {
		long long ans = 0;
		int decres = 0;
		int increase = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			int diff = target[i] - nums[i];
			if(diff > 0) {
				if(increase < diff) {
					int extra = diff - increase;
					ans += extra;
				}
				increase = diff;
				decres = 0;
			} else if(diff < 0) {
				if(decres < -diff) {
					int extra = -diff - decres;
					ans += extra;
				}
				decres = -diff;
				increase = 0;
			} else {
				decres = increase = 0;
			}
		}
		return ans;
	}
};