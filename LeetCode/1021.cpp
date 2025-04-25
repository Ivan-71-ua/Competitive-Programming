#include <bits/stdc++.h>


class Solution {
public:
	std::string removeOuterParentheses(std::string s) {
		std::string res;
		int open = 0;
		int close = 0;
		int start = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if(s[i] == ')')
				close++;
			else
				open++;
			if(close == open) {
				res += s.substr(start + 1, i - start - 1);
				start = i + 1;
			}
		}
		return res;
	}
};