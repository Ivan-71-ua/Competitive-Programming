#include <bits/stdc++.h>

class Solution {
public:
	int myAtoi(std::string s) {
		long long res = 0;
		int sign = 1;
		int i = 0;
		while(i < s.size() && s[i] == ' ')
			i++;
		if(s[i] == '-') {
			i++;
			sign *= -1;
		} else if(s[i] == '+') {
			i++;
		}
		while(i < s.size()) {
			if(isdigit(s[i])) {
				res = res * 10 + (s[i] - '0');
				if(res > INT32_MAX && sign == 1)
					return INT32_MAX;
				else if(res > INT32_MAX && sign == -1)
					return INT32_MIN;
				i++;
			} else {
				return res * sign;
			}
		}
		return res * sign;
	}
};