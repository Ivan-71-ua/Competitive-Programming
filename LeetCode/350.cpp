#include <bits/stdc++.h>



class Solution {
public:
	std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
		std::vector<int> ans;
		std::unordered_map<int, int> memor;
		for (int now: nums1)
		{
			memor[now]++;
		}
		for (int now: nums2)
		{
			if(memor.count(now)) {
				if(memor[now] > 0) {
					ans.push_back(now);
					memor[now]--;
				}
			}
		}
		return ans;
	}
};