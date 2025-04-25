#include <bits/stdc++.h>


class Solution {
	std::unordered_map<int, int> used;
	std::string st;
	bool check_is(std::string s, std::string rules) {
		for (int i = 0; i < rules.size(); i++)
		{
			if(rules[i] == 'I') {
				if(s[i] > s[i +1]) {
					return false;
				}
			} else {
				if(s[i] < s[i +1])
					return false;
			}
		}
		return true;
	}
	void built_intiger(std::string &res, std::string pat) {
		for (int i = 1; i <= used.size(); i++)
		{
			if(!used[i]) {
				st.push_back('0' + i);
				used[i] = 1;
				if(st.size()== used.size()) {
					if(check_is(st, pat)) {
						res = std::min(res, st);
					}
				}
				built_intiger(res, pat);
				used[i] = 0;
				st.pop_back();
			}
		}
	}
public:
	std::string smallestNumber(std::string pattern) {
		for (int i = 1; i <= pattern.size() + 1; i++)
		{
			used[i] = 0;
		}
		std::string res = "9999999999";
		built_intiger(res, pattern);
		return res;
	}
};