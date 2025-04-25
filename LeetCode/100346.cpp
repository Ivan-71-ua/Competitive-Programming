#include <bits/stdc++.h>




class Solution {
	public :
	int minOperations(std::vector<int> &nums)
	{
		int res = 0;
		int revers = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if(nums[i] == 0) {
				if(revers == 0) {
					revers = 1;
					res++;
				} 
			} else {
				if(revers) {
					res++;
					revers = 0;
				}
			}
		}
		return res;
	}
};

int main() {
	Solution ans;
	std::vector<int> ss{1,0,0,0};
	ans.minOperations(ss);
}