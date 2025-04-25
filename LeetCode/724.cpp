#include <bits/stdc++.h>

class Solution {
public:
   int pivotIndex(std::vector<int>& nums) {
		int sumL = 0, sumR = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			sumL += nums[i];
		}
		for (int i = 0; i < nums.size(); i++)
		{
			sumL -= nums[i];
			if(sumR == sumL)
				return i;
			sumR += nums[i];
		}
		return -1;
	}
};

int main() {
	Solution ans;
	std::vector<int> ss{1, 7, 3, 6, 5, 6};
	ans.pivotIndex(ss);
}