#include <bits/stdc++.h>



class Solution {
public:
	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
		int n = nums1.size(), m = nums2.size();
		std::vector<int> mer(n + m);
		std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), mer.begin());
		if((n + m) & 1) {
			return mer[(m + n) / 2];
		}
		return (mer[(m + n) / 2] + mer[(m + n) / 2 - 1]) / 2.0;
	}
};