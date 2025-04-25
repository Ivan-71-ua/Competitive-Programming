
#include <bits/stdc++.h>




class Solution {
public:
	std::vector<std::vector<int>> mergeArrays(std::vector<std::vector<int>>& nums1, std::vector<std::vector<int>>& nums2) {
		std::vector<int> sum(1002);
		for (auto &k: nums1) {
			sum[k[0]] += k[1];
		}
		for(auto &k: nums2) {
			sum[k[0]] += k[1];
		}
		std::vector<std::vector<int>> ans;
		for (int i = 1; i < 1001; i++) {
			if(sum[i]) {
				ans.push_back({i, sum[i]});
			}
		}
		return ans;
	}
};