
#include <bits/stdc++.h>

class Solution {
public:
	char kthCharacter(int k) {
		std::string s = "a";
		while(s.size() < k) {
			std::string tmp = s;
			for(char &c: tmp) {
				c = 'a' + ((c - 'a') + 1) % 26;
			}
			s += tmp;
		}
		return s[k - 1];
	}
};