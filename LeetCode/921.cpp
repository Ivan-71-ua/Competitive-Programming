#include <bits/stdc++.h>


class Solution {
public:
	int minAddToMakeValid(std::string s) {
		std::stack<char> valid;
		for (int i = 0; i < s.size(); i++)
		{
			if(valid.empty()) {
				valid.push(s[i]);
			} else if(valid.top() == '(' && s[i] == ')') {
				valid.pop();
			} else {
				valid.push(s[i]);
			}
		}
		return valid.size();
	}
};