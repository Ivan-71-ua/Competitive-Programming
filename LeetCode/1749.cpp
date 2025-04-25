#include <bits/stdc++.h>



class Solution {
public:
	int maxAbsoluteSum(std::vector<int>& nums) {
		int res = abs(nums[0]);
		int max_k = 0;
		int min_k = 0;
		for (int i = 0; i < nums.size(); i++) {
			max_k += nums[i];
			min_k += nums[i];
			res = std::max({max_k, abs(min_k), res});
			if(max_k < 0)
				max_k = 0;
			if(min_k > 0)
				min_k = 0;
		}
		return res;
	}
};
int main() {
	std::vector<int> ss{1,-3,2,3,-4};
	Solution ans;
	ans.maxAbsoluteSum(ss);
}