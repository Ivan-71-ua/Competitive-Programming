#include <bits/stdc++.h>


class Solution {
public:
	int reverse(long long x) {
		long long res = 0;
		bool neg = false;
		if(x < 0)  {
			neg = true;
			x *= -1;
		}
		while (x > 0) {
			res *= 10;
			res += x % 10;
			x /= 10;
		}
		if(res > INT32_MAX)
			return 0;
		if(neg)
			return -(int)res;
		return (int)res;
	}
};