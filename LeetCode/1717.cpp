#include <bits/stdc++.h>



class Solution {
public:
	int maximumGain(std::string s, int x, int y) {
		int res = 0;
		std::vector<char> st;
		for (int i = 0; i < s.size(); i++) {
			if(x > y) {
				if(!st.empty() && st.back() == 'a' && s[i] == 'b') {
					res += x;
					st.pop_back();
				} else {
					st.push_back(s[i]);
				}
			} else {
				if(!st.empty() && st.back() == 'b' && s[i] == 'a') {
					res += y;
					st.pop_back();
				} else {
					st.push_back(s[i]);
				}
			}
		}
		std::vector<char> st2;
		for (int i = 0; i < st.size(); i++) {
			if(x > y) {
				if(!st2.empty() && st2.back() == 'b' && st[i] == 'a') {
					res += y;
					st2.pop_back();
				} else {
					st2.push_back(st[i]);
				}
			} else {
				if(!st2.empty() && st2.back() == 'a' && st[i] == 'b') {
					res += x;
					st2.pop_back();
				} else {
					st2.push_back(st[i]);
				}
			}
		}
		return res;
	}
};