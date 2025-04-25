
#include <bits/stdc++.h>


class Solution {
public:
	void permut(std::string &s, int idx, std::vector<std::string> &res) {
		if (idx == s.size()) {
			res.push_back(s);
			return;
		}
		permut(s, idx + 1, res); 
		if (isalpha(s[idx])) { 
			s[idx] ^= 32; 
			permut(s, idx + 1, res); 
			s[idx] ^= 32; 
		}
	}
	std::vector<std::string> letterCasePermutation(std::string s) {
		std::vector<std::string> res;
		permut(s, 0, res);
		return res;
	}
};
