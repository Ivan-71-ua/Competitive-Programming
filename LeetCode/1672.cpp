
#include <bits/stdc++.h>



class Solution {
public:
	int maximumWealth(std::vector<std::vector<int>>& accounts) {
		int res = INT32_MIN;
		for (int i = 0; i < accounts.size(); i++)
		{
			int tmp = 0;
			for (auto &&i : accounts[i])
			{
				tmp += i;
			}
			res = std::max(res, tmp);
		}
		return res;
	}
};