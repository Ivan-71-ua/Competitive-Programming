#include <bits/stdc++.h>


class Solution {
public:
	int xorAllNums(std::vector<int>& nums1, std::vector<int>& nums2) {
		int k1 = nums1.size(), k2 = nums2.size();
		int res = 0;
		if(k1 & 1) {
			for(auto &v: nums2) {
				res ^= v;
			}
		}
		if(k2 & 1) {
			for(auto &v: nums1) {
				res ^= v;
			}
		}
		return res;
	}
};