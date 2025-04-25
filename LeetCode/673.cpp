#include <bits/stdc++.h>

class Solution {
public:
   int findNumberOfLIS(std::vector<int>& nums) {
		std::vector<int> max_len(nums.size(), 1);
		std::vector<int> max_numbrs(nums.size());
		for (int i = 0; i < nums.size(); i++)
		{
			int len = 0;
			for (int j = 0; j < i; j++)
			{
				if(nums[i] > nums[j]) {
					len = std::max(len, max_len[j]);
				}
			}
			if(len == 0) {
				max_numbrs[i] = 1;
			} else {
				for (int j = 0; j < i; j++)
				{
					if(nums[i] > nums[j] && len == max_len[j]) {
						max_numbrs[i] += max_numbrs[j];
					}
				}
			}
			max_len[i] = len + 1;
		}
		int max_l = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			max_l = std::max(max_l, max_len[i]);
		}
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if(max_l == max_len[i])
				sum += max_numbrs[i];
		}
		return sum;
	}
};

int main() {
	Solution ans;
	std::vector<int> ss{2,2,2,2,2};
	ans.findNumberOfLIS(ss);
}