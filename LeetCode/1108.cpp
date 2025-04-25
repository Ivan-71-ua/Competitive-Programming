
#include <bits/stdc++.h>

class Solution {
public:
	std::string defangIPaddr(std::string address) {
		std::string ans;
		for (auto ch: address)
		{
			if(ch == '.') {
				ans += "[.]";
				
			} else {
				ans += ch;
			}
		}
		return ans;
	}
};