#include <bits/stdc++.h>




class Solution {
public:
	int longestMonotonicSubarray(std::vector<int>& nums) {
		int res = 1;
		int k = 0;
		int cur = 1;
		for (int i = 1; i < nums.size(); i++) {
			if(k == 0) {
				if(nums[i] > nums[i - 1]) {
					k = 1;
					cur = 2;
				} else if(nums[i] < nums[i - 1]) {
					k = 2;
					cur = 2;
				} else {
					k = 0;
					cur = 1;
				}
			} else if(k == 1){
				if(nums[i] > nums[i - 1]) {
					cur++;
				} else if(nums[i] < nums[i - 1]){
					k = 2;
					res = std::max(res, cur);
					cur = 2;
				} else {
					k = 0;
					res = std::max(res, cur);
					cur = 1;
				}
			} else if(k == 2) {
				if(nums[i] < nums[i - 1]) {
					cur++;
				} else if(nums[i] > nums[i - 1]){
					k = 1;
					res = std::max(res, cur);
					cur = 2;
				} else {
					k = 0;
					res = std::max(res, cur);
					cur = 1;
				}
			}
		}
		res = std::max(res, cur);
		return res;
	}
};