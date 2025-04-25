
#include <bits/stdc++.h>

class Solution {
public:
   bool containsDuplicate(std::vector<int>& nums) {
		bool an = false;
		std::sort(nums.begin(), nums.end());
		for (int i = 1; i < nums.size(); i++)
		{
			if(nums[i-1] == nums[i]) {
				an = true;
				break;
			}
		}
		return an;
	}
};

int main() {
	Solution ans;
	std::vector<int> nums = {1,2,3,4};
	std::cout << ans.containsDuplicate(nums);
}