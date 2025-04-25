#include <bits/stdc++.h>


class Solution {
public:
	int firstMissingPositive(std::vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			if(nums[i] < 1 || nums[i] > n)
				nums[i] = n + 1;
		}
		for (int i = 0; i < n; i++)
		{
			int k = abs(nums[i]);
			if(k > n) continue;
			k--;
			if(nums[k] > 0)
				nums[k] *= -1;
		}
		
		for (int i = 0; i < nums.size(); i++) {
			if(nums[i] >= 0)
				return i + 1;
		}
		return n;
	}
};

int main() {
	Solution ans;
	std::vector<int> ss{3,4,-1,1};
	ans.firstMissingPositive(ss);
}