#include <bits/stdc++.h>


class Solution {
public:
   std::vector<int> SelectionSort(std::vector<int>& nums) {
      for (int i = nums.size() -1; i > 0; i--)
		{
			int m = nums[i];
			int x = i;
			for (int j = i - 1; j >= 0; j--)
			{
				if(m < nums[j]) {
					m = nums[j];
					x = j;
				}
			}
			nums[x] = nums[i];
			nums[i] = m;
		}
		return nums;
	}
};