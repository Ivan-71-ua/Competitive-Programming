#include <bits/stdc++.h>



class Solution {
	std::vector<std::string> res;
	void Creati_patern(int open, int close, int size, std::string st) {
		if(open > size || close > size)
			return;
		if(st.size() == size + size) {
			res.push_back(st);
			return;
		}
		if(open <= close) {
			st += '(';
			Creati_patern(open + 1, close, size, st);
			st.pop_back();
		} else {
			st += '(';
			Creati_patern(open + 1, close, size, st);
			st.pop_back();
			st += ')';
			Creati_patern(open, close + 1, size, st);
			st.pop_back();
		}
	}
public:
	std::vector<std::string> generateParenthesis(int n) {
		Creati_patern(0, 0, n, "");
		return res;
	}
};