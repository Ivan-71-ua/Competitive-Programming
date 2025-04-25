#include <bits/stdc++.h>

class Solution {
public:
	int countConsistentStrings(std::string allowed, std::vector<std::string>& words) {
		std::vector<int> can_use(26);
		for (auto ch: allowed)
		{
			can_use[ch - 'a']++;
		}
		int ans = 0;
		for (auto wd : words)
		{
			bool good = true;
			for (auto ch: wd)
			{
				if(can_use[ch - 'a'] == 0) {
					good = false;
					break;
				}
			}
			ans += good;
		}
		return ans;
	}
};