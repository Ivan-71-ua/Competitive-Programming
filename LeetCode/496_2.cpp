#include <bits/stdc++.h>

class Solution {
public:
   std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
		std::stack<int, std::vector<int>> greater;
		std::unordered_map<int, int> numToAns;
		for (int i = nums2.size() -1; i >= 0; i--)
		{
			while (!greater.empty() && greater.top() < nums2[i])
			{
				greater.pop();
			}
			if(greater.empty()) {
				numToAns[nums2[i]] = -1;
			} else {
				numToAns[nums2[i]] = greater.top();
			}
			greater.push(nums2[i]);
		}
		std::vector<int> ans(nums1.size());
		for (int i = 0; i < nums1.size(); i++)
		{
			ans[i] = numToAns[nums1[i]];
		}
		return ans;
	}
};