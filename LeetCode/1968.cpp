#include <bits/stdc++.h>


class Solution {
public:
   std::vector<int> rearrangeArray(std::vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		std::vector<int> ans(nums.size());
		int k = 0;
		for (int i = 1; i < nums.size(); i+= 2)
		{
			ans[i] = nums[k++];
		}
		for (int i = 0; i < nums.size(); i+= 2)
		{
			ans[i] = nums[k++];
		}
		return ans;
	}
};

int main() {
	Solution ans;
	std::vector<int> ss{1, 3, 2, 4, 5, 7};
	ans.rearrangeArray(ss);
}