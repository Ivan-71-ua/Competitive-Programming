#include <bits/stdc++.h>


class Solution {
public:
	std::string makeFancyString(std::string s) {
		int n = s.size();
        if(n < 3) {
            return s;
        }
		std::string res = "";
		for (int i = 0; i < n - 2; i++) {
			if(s[i] != s[i + 1] || s[i + 1] != s[i + 2]) {
				res += s[i];
			}
		}
		res += s[n - 2];
		res += s[n - 1];
		return res;
	}
};