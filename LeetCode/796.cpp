#include <bits/stdc++.h>


class Solution {
public:
	bool rotateString(std::string s, std::string goal) {
		if(s.size() != goal.size())
			return false;
		s += s;
		if(s.find(goal) != std::string::npos)
			return true;
		return false;
	}
};