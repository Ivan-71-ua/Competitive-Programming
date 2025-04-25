#include <bits/stdc++.h>

class Solution {
public:
   bool isValid(std::string s) {
		std::stack<char> stair;
		for (int i = 0; i < s.size(); i++)
		{
			if(stair.empty()) {
				stair.push(s[i]);
			} else {
				if(stair.top() == '(' && s[i] == ')' || stair.top() == '{' && s[i] == '}' || stair.top() == '[' && s[i] == ']') {
					stair.pop();
				} else {
					stair.push(s[i]);
				}
			}
		}
		return stair.empty();
	}
};