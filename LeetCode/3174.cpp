#include <bits/stdc++.h>



class Solution {
public:
	std::string clearDigits(std::string s) {
		std::deque<char> q;
		for (int i = 0; i < s.size(); i++) {
			if(isalpha(s[i])) {
				q.push_back(s[i]);
			} else {
				q.pop_back();
			}
		}
		std::string res;
		while(!q.empty()) {
			res += q.front();
			q.pop_front();
		}
		return res;
	}
};