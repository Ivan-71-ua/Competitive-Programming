#include <bits/stdc++.h>


class Solution {
public:
	std::string getEncryptedString(std::string s, int k) {
		std::string st;
		for (int i = 0; i < s.size(); i++)
		{
			st += s[(i + k) % s.size()];
		}
		return st;
	}
};