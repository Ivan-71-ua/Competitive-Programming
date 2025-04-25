#include <bits/stdc++.h>



class Solution {
public:
	std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
		std::vector<int> ans;
		std::stable_sort(nums1.begin(), nums1.end());
		std::stable_sort(nums2.begin(), nums2.end());
		int a = 0;
		int b = 0;
		while(a < nums1.size() && b < nums2.size()) {
			if(nums1[a] < nums2[b]) {
				a++;
			} else if(nums1[a] > nums2[b]) {
				b++;
			} else {
				ans.push_back(nums1[a]);
				a++;
				b++;
			}
		}
		return ans;
	}
};