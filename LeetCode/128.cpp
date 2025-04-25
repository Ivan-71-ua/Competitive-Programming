#include <bits/stdc++.h>

	class Solution {
	public:
		int longestConsecutive(std::vector<int>& nums) {
			if(nums.empty())
				return 0;
			bool positive_nums[100000001] = {};
			bool negative_nums[100000001] = {};
			for (int i = 0; i < nums.size(); i++)
			{
				if(nums[i] > 0)
					positive_nums[nums[i]] = true;
				else if(nums[i] < 0)
					negative_nums[abs(nums[i])] = true;
				else {
					positive_nums[0] = true;
					negative_nums[0] = true;
				}
			}
			int max = -1;
			int temp = 1;
			for (int i = 100000000; i >= 0; i--)
			{
				if(negative_nums[i] == true && negative_nums[i +1] == true)
					temp++;
				else {
					if(max < temp)
						max = temp;
					temp = 1;
				}
			}
			for (int i = 1; i < 100000000; i++)
			{
				if(positive_nums[i-1] == true && positive_nums[i] == true)
					temp++;
				else {
					if(max < temp)
						max = temp;
					temp = 1;
				}
			}
			return max;
		}
	};

int main() {
	Solution ans;
	std::vector an{100, 4, 200, 1, 3, 2};
	ans.longestConsecutive(an);
}