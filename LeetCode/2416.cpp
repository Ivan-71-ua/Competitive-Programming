#include <bits/stdc++.h>


class Solution {
public:
	std::vector<int> sumPrefixScores(std::vector<std::string>& words) {
		int n = words.size();
		std::unordered_map<std::string, int> pref_words;
		for (auto &wd: words)
		{
			std::string tmp;
			for(auto &ch: wd) {
				tmp += ch;
				pref_words[tmp]++;
			}
		}
		std::vector<int> ans(n);
		for (int i = 0; i < n; i++)
		{
			std::string tmp;
			for(auto &ch: words[i]) {
				tmp += ch;
				ans[i] += pref_words[tmp];
			}
		}
		return ans;
	}
};