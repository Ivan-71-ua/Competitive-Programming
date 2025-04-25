#include <bits/stdc++.h>

class Solution {
public:
   std::vector<int> BubbleSort(std::vector<int>& nums) {
      for (int i = 0; i < nums.size(); i++)
		{
			for (int j = 0; i < nums.size() - 1 - i; j++)
			{
				if(nums[j] > nums[j + 1])
					std::swap(nums[j], nums[j + 1]);
			}
			
		}
		
	}
};