#include <bits/stdc++.h>



class Solution {
public:
	int minSteps(std::string s, std::string t) {
		std::vector<int> alph(26);
		for(auto ch: s) {
			alph[ch - 'a']++;
		}
		for (auto ch: t)
		{
			alph[ch - 'a']--;
		}
		int ans = 0;
		for(auto now: alph) {
			ans += abs(now);
		}
		return ans;
	}
};