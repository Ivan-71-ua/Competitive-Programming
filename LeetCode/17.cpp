#include <bits/stdc++.h>




class Solution {
	std::vector<std::string> nums{
		"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" 
	};
	std::vector<std::string> res;
	std::string tmp;
	void comb(int idx, int k, std::string &digits) {
		if(idx == k) {
			res.push_back(tmp);
			return;
		}
		for (auto &ch: nums[digits[idx] - '0'])
		{
			tmp += ch;
			comb(idx + 1, k, digits);
			tmp.pop_back();
		}
	}
public:
	std::vector<std::string> letterCombinations(std::string digits) {
		if(digits.size() == 0)
			return {};
		comb(0, digits.size(), digits);

		return res;
	}
};