#include <bits/stdc++.h>



class Solution {
public:
	int search(std::vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if(nums[mid] == target)
				return mid;
			else if(nums[mid] > target)
				r = mid - 1;
			else if(nums[mid] < target)
				l = mid + 1;
		}
		return -1;
	}
};