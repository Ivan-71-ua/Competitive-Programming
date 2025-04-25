#include <bits/stdc++.h>


class Solution {
public:
	bool repeatedSubstringPattern(std::string s) {
		for (int period = 1; 2 * period <= s.size(); period++)
		{
			if(s.size() % period == 0) {
				bool good = true;
				for (int i = s.size() -1; i >= period; i--)
				{
					if(s[i] != s[i - period]) {
						good = false;
						break;
					}
				}
				if(good) {
					return true;
				}
			}
		}
		return false;
	}
};