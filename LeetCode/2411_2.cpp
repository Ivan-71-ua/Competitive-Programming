
#include <bits/stdc++.h>

class Solution {
public:
	std::vector<int> smallestSubarrays(std::vector<int>& nums) {
		int n = nums.size();
		std::vector<int> ans(n, 1);
		for (int i = 0; i < n; i++)
		{
			int j = i - 1;
			while(j > -1 && ((nums[i] | nums[j]) != nums[j])) {
				ans[j] = i - j + 1;
				nums[j] |= nums[i];
				j--;
			}
		}
		return ans;
	}
};