
#include <bits/stdc++.h>




class Solution {
public:
	bool canBeValid(std::string s, std::string locked) {
		int n = s.size();
		if(n & 1)
			return false;
		std::stack<int> open, unlock;
		for (int i = 0; i < n; i++) {
			if(locked[i] == '0') {
				unlock.push(i);
			} else if(s[i] == '(') {
				open.push(i);
			} else {
				if(!open.empty()) {
					open.pop();
				} else if(!unlock.empty()) {
					unlock.pop();
				} else {
					return false;
				}
			}
		}
		while(!open.empty() && !unlock.empty() && open.top() < unlock.top()) {
			unlock.pop();
			open.pop();
		}
		if(!open.empty())
			return false;
		return true;
	}
};