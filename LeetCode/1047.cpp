#include <bits/stdc++.h>


class Solution {
public:
	std::string removeDuplicates(std::string s) {
		std::deque<char> way;
		way.push_back('@');
		for (int i = 0; i < s.size(); i++)
		{
			if(way.back() == s[i]) {
				while(way.back() == s[i]) {
					way.pop_back();
				}
			} else {
				way.push_back(s[i]);
			}
		}
		way.pop_front();
		std::string res;
		while(!way.empty()) {
			res += way.front();
			way.pop_front();
		}
		return res;
	}
};