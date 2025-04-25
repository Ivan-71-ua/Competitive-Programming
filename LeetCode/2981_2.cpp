#include <bits/stdc++.h>


class Solution {
public:
	int maximumLength(std::string s) {
		std::vector<std::vector<int>> alph(26, std::vector<int>(3, -1));
		char last_seen = '%';
		int min_len = 0;
		for (auto &&cur : s)
		{
			int idx = cur - 'a';
			if(cur == last_seen)
				min_len++;
			else
				min_len = 1;
			last_seen = cur;
			int minimum = std::min({alph[idx][0], alph[idx][1], alph[idx][2]});
			if(min_len > minimum) {
				for (auto &j : alph[idx])
				{
					if(j == minimum) {
						j = min_len;
						break;
					}
				}
			}
		}
		int max_len = -1;
		for (int i = 0; i < 26; i++)
		{
			max_len = std::max(max_len, std::min({alph[i][0], alph[i][1], alph[i][2]}));
		}
		return max_len;
	}
};