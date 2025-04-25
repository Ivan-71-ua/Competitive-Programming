#include <bits/stdc++.h>




class Solution {
public:
	std::string reverseParentheses(std::string s) {
		std::string res;
		std::stack<int> st;
		for (int i = 0; i < s.size(); i++) {
			if(s[i] == '(') {
				st.push(i);
			} else if(s[i] == ')'){
				std::reverse(s.begin() + st.top() + 1, s.begin() + i);
				st.pop();
			} 
		}
		for (int i = 0; i < s.size(); i++) {
			if(s[i]!= '(' && s[i] != ')')
				res += s[i];
		}
		return res;
	}
};	