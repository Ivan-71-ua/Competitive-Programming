#include <bits/stdc++.h>


class Solution {
public:
	std::vector<std::vector<int>> largeGroupPositions(std::string s) {
		s += '@';
		std::vector<std::vector<int>> res;
		char cur = '1';
		int st = -1;
		int fn = -1;
		for (int i = 0; i < s.size(); i++)
		{
			if(cur != s[i]) {
				if(fn - st > 1) {
					res.push_back({st, fn});
				}
				cur = s[i];
				st = fn = i;
			} else {
				fn++;
			}
		}
		return res;
	}
};