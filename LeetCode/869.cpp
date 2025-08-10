
#include <bits/stdc++.h>

class Solution {
	std::string count_dig(int num) {
		std::string tmp = "";
		while(num) {
			tmp += '0' + num % 10;
			num /= 10;
		}
		std::sort(tmp.begin(), tmp.end());
		return tmp;
	}
public:
	bool reorderedPowerOf2(int n) {
		if((n & (n -1)) == 0)
			return true;
		std::string target = count_dig(n);
		for (int i = 0; i < 31; i++) {
			if(target == count_dig(1 << i)) {
				return true;
			}
		}
		return false;
	}
};