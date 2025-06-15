#include <bits/stdc++.h>



class Solution {
public:
	int maxDiff(int num) {
		std::string s = std::to_string(num);
		char maxd = '@';
		for (char c : s) {
			if (c != '9') {
				maxd = c;
				break;
			}
		}
		char mind = '@';
		bool first = false;
		if(s[0] != '1') {
			mind = s[0];
			first = true;
		} else {
			for (char c : s) {
				if (c != '1' && c != '0') {
					mind = c;
					break;
				}
			}
		}
		
		long long maxn = 0, minn = 0;
		for (char c : s) {
			maxn = maxn * 10 + (c == maxd ? '9' : c);
			minn = minn * 10 + (c == mind ? (first ? '1' : '0') : c);
		}
		return maxn - minn;
	}
};