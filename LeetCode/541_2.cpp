#include <bits/stdc++.h>


class Solution {
public:
	std::string reverseStr(std::string s, int k) {
		for (int i = 0; i < s.size(); i += 2*k) reverse(s.begin()+i, min(s.begin()+i+k, s.end()));
		return s;
	}
};