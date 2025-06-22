

#include <bits/stdc++.h>

class Solution {
public:
	std::vector<std::string> divideString(std::string s, int k, char fill) {
		int ost = s.size() % k;
		ost == 0 ? ost = 0 : ost = k - ost;
		for (int i = 0; i < ost; i++) {
			s.push_back(fill);
		}
		std::vector<std::string> res;
		for (int i = 0; i < s.size(); i += k) {
			res.push_back(s.substr(i, k));
		}
		return res;
	}
};