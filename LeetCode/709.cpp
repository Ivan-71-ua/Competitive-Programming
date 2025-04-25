#include <bits/stdc++.h>


class Solution {
public:
	std::string toLowerCase(std::string s) {
		for (int i = 0; i < s.size(); i++)
		{
			s[i] = std::tolower(s[i]);
		}
		
		return s;
	}
};