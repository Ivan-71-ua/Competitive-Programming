#include <bits/stdc++.h>

class Solution {
public:
   int removeElement(std::vector<int>& nums, int val) {
		int k = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if(nums[i] != val) {
				nums[k] = nums[i];
				k++;
			}
		}
		return k;
	}
};

int main() {
	Solution ans;
	std::vector<int> nums{4,5};
	ans.removeElement(nums, 5);
}