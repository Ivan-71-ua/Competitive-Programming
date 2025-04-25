#include <bits/stdc++.h>

class Solution {
	std::vector<std::string> res;
	void createPattern(int open, int close, int size, std::string& st) {
		if (open > size || close > size)
			return;
		if (st.size() == size * 2) {
			res.push_back(st);
			return;
		}
		if (open < size) {
			st.push_back('(');
			createPattern(open + 1, close, size, st);
			st.pop_back();
		}
		if (close < open) {
			st.push_back(')');
			createPattern(open, close + 1, size, st);
			st.pop_back();
		}
	}
	
public:
	std::vector<std::string> generateParenthesis(int n) {
		std::string st;
		createPattern(0, 0, n, st);
		return res;
	}
};
