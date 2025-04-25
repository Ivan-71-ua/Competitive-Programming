#include <bits/stdc++.h>


	class Solution {
	public:
		int repeatedNTimes(std::vector<int>& nums) {
			std::vector<int> nm(10e4 +1);
			for (auto &now: nums)
			{
				nm[now]++;
			}
			for (int i = 0; i < nm.size(); i++)
			{
				if(nm[i] == nums.size() / 2)
					return i;
			}
			return 0;
		}
	};
