#include <bits/stdc++.h>

class Solution {
public:
	std::string reverseStr(std::string s, int k) {
		if(s.size() <= k) {
			std::reverse(s.begin(), s.end());
			return s;
		}
		for (int i = 0; i < s.size(); i += k)
		{
			std::reverse(s.begin() + i, i + k < s.size() ? s.begin() + i + k : s.end());
			i += k;
		}
		return s;
	}
};

int main() {
	Solution ans;
	ans.reverseStr("abcdefg", 3);
}