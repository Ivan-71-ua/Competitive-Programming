
#include <bits/stdc++.h>

class Solution {
public:
	int countSegments(std::string s) {
		if(s.empty())
			return 0;
		std::vector<std::string> res;
		//std::string char = "!@#$%^&*()_+-=',.:";
		for (int i = 0; i < s.size(); i++)
		{
			if(s[i] != ' ')  {
				std::string tmp;
				tmp += s[i];
				i++;
				while(s[i] != ' ' && i != s.size()) {
					tmp += s[i];
					i++;
				}
				res.push_back(tmp);
			}
		}
		return res.size();
	}
};

int main() {
	Solution ans;
	ans.countSegments("a");
}