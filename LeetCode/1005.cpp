#include <bits/stdc++.h>


class Solution {
public:
	int largestSumAfterKNegations(std::vector<int>& nums, int k) {
		std::stable_sort(nums.begin(), nums.end());
		if (nums[0] > 0) {
			if(k & 1){
				nums[0] *= -1;
			}
		} else if(nums[0] < 0) {
			int j = 0;
			while(k && j + 1 < nums.size()) {
				if(nums[j] > 0) break;
				nums[j] = -nums[j];
				j++;
				k--;
			}
			if(k & 1) {
				if(abs(nums[j]) > abs(nums[j -1])) {
					nums[j - 1] *= -1;
				} else {
					nums[j] *= -1;
				}
			}
		}
		int sum = 0;
		for (auto now: nums)
		{
			sum += now;
		}
		return sum;
	}
};

int main() {
	Solution ans;
	std::vector<int> res {-4,-2,-3};
	ans.largestSumAfterKNegations(res, 9);
}