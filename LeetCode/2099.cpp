
#include <bits/stdc++.h>

class Solution {
public:
	std::vector<int> maxSubsequence(std::vector<int>& nums, int k) {
		int n = nums.size();
		std::vector<int> sorted = nums;
		std::stable_sort(sorted.begin(), sorted.end());
		std::unordered_map<int, int> cnt;
		for (int i = n - k; i < n; i++) {
			cnt[sorted[i]]++;
		}
		std::vector<int> ans;
		for (int i = 0; i < n; i++ ) {
			if(cnt[nums[i]] > 0) {
				ans.push_back(nums[i]);
				cnt[nums[i]]--;
			}
			if(ans.size() == k) {
				break;
			}
		}
		return ans;
	}
};
