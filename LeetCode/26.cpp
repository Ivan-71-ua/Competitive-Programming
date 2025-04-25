#include <bits/stdc++.h>

class Solution {
public:
   int removeDuplicates(std::vector<int>& nums) {
		int k, l;
		k = 1;
		l = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if(nums[i] != nums[l]) {
				k++;
				std::swap(nums[i], nums[++l]);
			}
		}
		return k;
	}
};