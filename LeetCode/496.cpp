#include <bits/stdc++.h>

class Solution {
public:
   std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
		for (int i = 0; i < nums1.size(); i++)
		{
			int max = -1;
			for (int j = nums2.size() -1; nums1[i] != nums2[j]; j--)
			{
				if(nums1[i] < nums2[j])
					max = nums2[j];
			}
			nums1[i] = max;
		}
		return nums1;
	}
};