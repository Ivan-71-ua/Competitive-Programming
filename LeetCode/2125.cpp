#include <bits/stdc++.h>


class Solution {
public:
	int numberOfBeams(std::vector<std::string>& bank) {
		int ans = 0;
		int prev= std::count(bank[0].begin(), bank[0].end(), '1');
		for (int i = 1; i < bank.size(); i++)
		{
			int cur = std::count(bank[i].begin(), bank[i].end(), '1');
			if(cur) {
				ans += prev * cur;
				prev = cur;
			}
		}
		return ans;
	}
};