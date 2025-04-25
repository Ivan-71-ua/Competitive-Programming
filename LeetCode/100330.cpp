#include <bits/stdc++.h>

class Solution {
public:
	int minimumLength(std::string s) {
		std::vector<int> alph(26);
		for (int i = 0; i < s.size(); i++)
		{
			alph[s[i] - 'a']++;
		}
		int res = 0;
		for (auto &now: alph)
		{
			if(now > 0)
				res += now % 2 == 0 ? 2 : 1;
		}
		return res;
	}
};