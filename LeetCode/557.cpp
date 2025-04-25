#include <bits/stdc++.h>

class Solution {
public:
	std::string reverseWords(std::string s) {
		std::string res;
		std::stringstream parse(s);
		std::string tmp;
		while(parse >> tmp) {
			std::reverse(tmp.begin(), tmp.end());
			res += tmp + ' ';
		}
		res.pop_back();
		return res;
	}
};