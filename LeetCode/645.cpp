#include <bits/stdc++.h>


	class Solution {
	public:
		std::vector<int> findErrorNums(std::vector<int>& nums) {
			int res = ((1 + nums.size()) * nums.size()) / 2;
			std::map<int, int> dig;
			for (int i = 0; i < nums.size(); i++)
			{
				dig[nums[i]]++;
			}
			int fl;
			for (auto now: dig)
			{
				res -= now.first;
				if(now.second == 2) {
					fl = now.first;
				}
			}
			return { fl, res};
		}
	};

int main() {
	Solution ans;
	std::vector<int> ss{1, 2, 2, 4};
	ans.findErrorNums(ss);
}