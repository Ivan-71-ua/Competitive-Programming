#include <bits/stdc++.h>


class Solution {
public:
   std::string toHex(int num) {
		std::string tabl = "0123456789abcdef";
		if(num == 0)
			return "0";
		unsigned long long tp;
		if(num < 0) {
			tp += 4294967296 + num;
		} else {
			tp = num;
		}
		std::string ans;
		while (tp != 0) {
			int k = tp % 16;
			tp /= 16;
			ans += tabl[k];
		}
		return {ans.rbegin(), ans.rend()};
	}
};