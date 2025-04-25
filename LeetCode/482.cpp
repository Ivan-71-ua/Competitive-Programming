#include <bits/stdc++.h>


class Solution {
public:
	std::string licenseKeyFormatting(std::string s, int k) {
		std::vector<std::string> res;
		std::string tmp;
		for (int i = s.size() -1; i >= 0; i--)
		{
			if(tmp.size() == k) {
				std::reverse(tmp.begin(), tmp.end());
				res.push_back(tmp);
				tmp = "";
				if(isalpha(s[i])) {
					tmp += toupper(s[i]);
				} else if(isdigit(s[i])) {
					tmp += s[i];
				}
			} else {
				if(isalpha(s[i])) {
					tmp += toupper(s[i]);
				} else if(isdigit(s[i])) {
					tmp += s[i];
				}
			}
		}
		if(tmp != "") {
			std::reverse(tmp.begin(), tmp.end());
			res.push_back(tmp);
			tmp = "";
		}
		for (int i = res.size() - 1; i >= 0; i--)
		{
			if(i != 0) {
				tmp += res[i] + '-';
			} else {
				tmp += res[i];
			}
		}
		
		return tmp;
	}
};

int main() {
	Solution ans;
	ans.licenseKeyFormatting("5F3Z-2e-9-w", 4);
}