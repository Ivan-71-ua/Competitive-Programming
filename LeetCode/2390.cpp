#include <bits/stdc++.h>


class Solution {
public:
	std::string removeStars(std::string s) {
		std::deque<char> remove;
		for (int i = 0; i < s.size(); i++)
		{
			if(s[i] == '*') {
				remove.pop_back();
			} else {
				remove.push_back(s[i]);
			}
		}
		std::string res;
		while (!remove.empty()) 
		{
			res += remove.front();
			remove.pop_front();
		}
		return res;
	}
};