#include <bits/stdc++.h>


class Solution {
public:
	int minSteps(std::string s, std::string t) {
		std::vector<int> alphabet(26);
		for (int i = 0; i < s.size(); i++)
		{
			alphabet[s[i] - 'a']--;
			alphabet[t[i] - 'a']++;
		}
		int res = 0;
		for (auto now: alphabet)
		{
			if(now > 0)
				res += now;
		}
		return res;
	}
};