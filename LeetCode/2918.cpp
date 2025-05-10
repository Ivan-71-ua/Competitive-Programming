
#include <bits/stdc++.h>


class Solution {
public:
	long long minSum(std::vector<int>& nums1, std::vector<int>& nums2) {
		long long sum1 = 0, sum2 = 0;
		int n = nums1.size(), m = nums2.size(), k1 = 0, k2 = 0;
		for (int i = 0; i < n; i++) {
			if(nums1[i] == 0) {
				k1++;
				sum1++;
			} else {
				sum1 += nums1[i];
			}
		}
		for (int i = 0; i < m; i++) {
			if(nums2[i] == 0) {
				k2++;
				sum2++;
			} else {
				sum2 += nums2[i];
			}
		}

		if(sum1 > sum2) {
			std::swap(sum1, sum2);
			std::swap(k1, k2);
		}
		if(k1 * k2 > 0 || (k2 == 0 && k1 != 0)) {
			return sum2;
		}
		return -1;
	}
};