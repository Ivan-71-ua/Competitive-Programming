#include <bits/stdc++.h>




class Solution {
	int count_one(int n) {
		int res = 0;
		while(n) {
			res += n % 2;
			n /= 2;
		}
		return res;
	}

public:
	bool canSortArray(std::vector<int>& nums) {
		int n = nums.size();
		bool isSorted = true;
		for (int i = 1; i < n; i++) {
			if(nums[i -1] > nums[i]) {
				isSorted = false;
				break;
			}
		}
		if(isSorted)
			return true;
		std::unordered_map<int, int> num_ones;
		for (auto &&n : nums)
		{
			num_ones[n] = count_one(n);
		}
		for (int i = 0; i < n - 1; i++)
		{
			isSorted = true;
			for (int j = 0; j < n - i - 1; j++)
			{
				if(nums[j] > nums[j +1] && num_ones[nums[j]] == num_ones[nums[j +1]]) {
					std::swap(nums[j], nums[j +1]);
					isSorted = false;
				}
			}
			if(isSorted) break;
		}
		isSorted = true;
		for (int i = 1; i < n; i++) {
			if(nums[i -1] > nums[i]) {
				isSorted = false;
				break;
			}
		}
		return isSorted;
	}
};