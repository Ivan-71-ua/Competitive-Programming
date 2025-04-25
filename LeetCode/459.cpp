#include <bits/stdc++.h>


class Solution {
public:
	bool repeatedSubstringPattern(std::string s) {
		std::string tmp(++s.begin(), s.end());
		std::string tmp2(s.begin(), --s.end());
		std::string res = tmp + tmp2;
		if(res.find(s) != std::string::npos)
				return true;
		return false;
	}
};

int main() {
	Solution ans;
	ans.repeatedSubstringPattern("abab");
}