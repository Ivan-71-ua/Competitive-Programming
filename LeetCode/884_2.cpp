#include <bits/stdc++.h>


class Solution {
public:
	std::vector<std::string> uncommonFromSentences(std::string s1, std::string s2) {
		std::string str;
		std::map<std::string, int> mp;
		std::vector<std::string> ans;
		std::istringstream ss;
		ss.str(s1 + " " + s2);
		while (ss >> str) {
			mp[str]++;
		}
		for (auto x : mp) {
			if (x.second == 1) {
				ans.push_back(x.first);
			}
		}
	return ans;
	}
};