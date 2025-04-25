#include <bits/stdc++.h>


class Solution {
public:
	std::string convertToBase7(int num) {
		bool neg = false;
		if(num < 0) {
			num *= -1;
			neg = true;
		}
		std::string res;
		while(num != 0) {
			res += ('0' + (char)(num % 7));
			num /= 7;
		}
		std::reverse(res.begin(), res.end());
		if(neg) {
			return '-' + res;
		} else {
			return res;
		}
	}
};


int main() {
	Solution ans;
	ans.convertToBase7(100);
}