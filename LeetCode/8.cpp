#include <bits/stdc++.h>


class Solution {
public:
	int myAtoi(std::string s) {
		long long res = 0;
		bool neg = false;
		int i = 0;
		while(s[i] == ' ')
			i++;
		if(isalpha(s[i]))
			return 0;
		neg = s[i] == '-';
		if(s[i] == '-' || s[i] == '+')
			i++;
		while(isdigit(s[i])) {
			if(res > INT32_MAX / 10)  {
				if(neg)
					return INT32_MIN;
				else
					return INT32_MAX;
			}
			res *= 10;
			res += s[i] - '0';
			i++;
		}
		if(neg)
			res *= -1;
		if(res > INT32_MAX)
			return INT32_MAX;
		if(res < INT32_MIN)
			return INT32_MIN;
		return res;
	}
};