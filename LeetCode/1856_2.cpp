#include <bits/stdc++.h>


class Solution {
public:
   int maxSumMinProduct(std::vector<int>& nums) {
		std::vector<int> pref(nums.size() + 1);
		std::vector<int> left_min(nums.size());
		std::vector<int> right_min(nums.size());
		for (int i = 1; i < nums.size() +1; i++)
		{
			pref[i] = pref[i - 1] + nums[i - 1];
		}
		//left
		left_min[0] = -1;
		for (int i = 1; i < nums.size(); i++)
		{
			int j = i;
			while(nums[j] >= nums[i] && j -1 > 0) {
				j--;
			}
			j--;
			left_min[i] = j;
		}
		right_min[right_min.size() - 1] = nums.size();
		for (int i = 0; i < nums.size() - 1; i++)
		{
			int j = i;
			while(nums[i] <= nums[j] && j + 1 < nums.size()) {
				j++;
			}
			j++;
			right_min[i] = j;
		}
		
	}
};

int main() {
	Solution ans;
	std::vector<int> ss{2, 3, 3, 1, 2};
	ans.maxSumMinProduct(ss);
}