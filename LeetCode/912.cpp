#include <bits/stdc++.h>


class Solution {
public:
   std::vector<int> InsertionSort(std::vector<int>& nums) {
      for (int i = 1; i < nums.size(); i++)
		{
			int m = nums[i];
			int j = i - 1;
			while (j >= 0 && m < nums[j])
			{
				nums[j + 1] = nums[j];
				j--;
			}
			nums[j + 1] = m;
		}
		return nums;
	}
};