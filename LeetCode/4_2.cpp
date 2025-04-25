#include <bits/stdc++.h>



class Solution {
public:
	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
		int n = nums1.size();
		int m = nums2.size();
		int n_m = n + m;
		if(n_m & 1) {
			return binaryserch(nums1, nums2, n_m / 2, 0, n - 1, 0, m - 1);
		}
		return (binaryserch(nums1, nums2, n_m / 2, 0, n - 1, 0, m - 1) + binaryserch(nums1, nums2, n_m / 2 - 1, 0, n - 1, 0, m - 1)) / 2.0;
	}
	int binaryserch(std::vector<int> a, std::vector<int> b, int kth, int s_a, int f_a, int s_b, int f_b) {
		if(s_a > f_a) {
			return b[kth - s_a];
		}
		if(s_b > f_b) {
			return a[kth - s_b];
		}
		int m_a = s_a + (f_a - s_a) / 2;
		int m_b = s_b + (f_b - s_b) / 2;
		int v_a = a[m_a], v_b = b[m_b];
		if(m_a + m_b < kth) {
			if(v_a > v_b) {
				return binaryserch(a, b, kth, s_a, f_a, m_b + 1, f_b);
			} else {
				return binaryserch(a, b, kth, m_a + 1, f_a, s_b, f_b);
			}
		} else {
			if(v_a > v_b) {
				return binaryserch(a, b, kth, s_a, m_a - 1, s_b, f_b);
			} else {
				return binaryserch(a, b, kth, s_a, f_a, s_b, m_b - 1);
			}
		}
		return -1;
	}
};



