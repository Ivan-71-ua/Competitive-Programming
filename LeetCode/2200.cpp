
#include <bits/stdc++.h>



class Solution {
public:
	std::vector<int> findKDistantIndices(std::vector<int>& nums, int key, int k) {
		int  n = nums.size();
		std::vector<int> ans;
		for (int i = 0; i < n; i++) {
			if(nums[i] == key) {
				int left = std::max(0, i - k);
				int right = std::min(n - 1, i + k);
				for (int j = left; j <= right; j++) {
					if(nums[j] == key && j > i) break;
					if(nums[j] != -1) continue;
					nums[j] = -1;
					ans.push_back(j);
				}
			}
		}
		return ans;
	}
};