#include <bits/stdc++.h>

class Solution {
public:
	char findTheDifference(std::string s, std::string t) {
		int res = 0;
		for (int i = 0; i < s.size(); i++)
		{
			res ^= s[i];
		}
		for (int i = 0; i < t.size(); i++)
		{
			res ^= t[i];
		}
		return (char)res;
	}
};