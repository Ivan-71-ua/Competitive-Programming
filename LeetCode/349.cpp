#include <bits/stdc++.h>

class Solution {
public:
	std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
		std::set<int> res;
		for (int i = 0; i < nums1.size(); i++)
		{
			if(std::find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end()) {
				res.insert(nums1[i]);
			}
		}
		return {res.begin(), res.end()};
	}
};