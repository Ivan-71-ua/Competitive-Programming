
#include <bits/stdc++.h>

class Solution {
public:
	int maxCount(std::vector<int>& banned, int n, int maxSum) {
		std::vector<int> nums(10000 + 3, 1);
		for (auto &&i : banned)
		{
			nums[i] = 0;
		}
		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			if(nums[i] == 0) continue;
			if(maxSum >= i) {
				res++;
				maxSum -= i;
			} else {
				break;
			}
		}
		return res;
	}
};