#include <bits/stdc++.h>

class Solution {
public:
	int thirdMax(std::vector<int>& nums) {
		long long firs = INT64_MIN;
		long long sec = INT64_MIN;
		long long third = INT64_MIN;
		for (int i = 0; i < nums.size(); i++)
		{
			if(nums[i] > firs) {
				third = sec;
				sec = firs;
				firs = nums[i];
			} else if(firs > nums[i] && nums[i] > sec) {
				third = sec;
				sec = nums[i];
			} else if(sec > nums[i] && nums[i] > third) {
				third = nums[i];
			}
		}
		return third == INT64_MIN ?  firs :  third;
	}
};