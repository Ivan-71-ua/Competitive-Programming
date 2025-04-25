#include <bits/stdc++.h>


class Solution {
	bool can(std::vector<int> can_used, std::string st) {
		for (auto ch: st)
		{
			can_used[ch - 'a']--;
			if(can_used[ch - 'a'] < 0)
				return false;
		}
		return true;
	}
public:
	int countCharacters(std::vector<std::string>& words, std::string chars) {
		std::vector<int> can_use(26);
		int ans = 0;
		for (auto ch: chars)
		{
			can_use[ch - 'a']++;
		}
		for (auto word: words)
		{
			if(can(can_use, word))
				ans += word.size();
		}
		return ans;
	}
};