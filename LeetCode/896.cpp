
#include <bits/stdc++.h>


class Solution {
public:
	bool isMonotonic(std::vector<int>& nums) {
		bool max = true;
		bool min = true;
		for (int i = 1; i < nums.size(); i++)
		{
			if(nums[i-1] > nums[i]) {
				max = false;
				break;
			}
		}
		for (int i = 1; i < nums.size(); i++)
		{
			if(nums[i-1] < nums[i]) {
				min = false;
				break;
			}
		}
		return max | min;
	}
};

int main() {
	Solution ANS;
	std::vector<int> res{1, 3, 2};
	ANS.isMonotonic(res);
}