#include <bits/stdc++.h>





class Solution {
public:
	std::string countAndSay(int n) {
		if( n == 1) {
			return "1";
		}
		std::string prev = countAndSay(n - 1);
		std::string res = "";
		int cnt = 1;
		for (int i = 1; i < prev.size(); i++) {
			if(prev[i - 1] == prev[i]) {
				cnt++;
			} else {
				res += std::to_string(cnt) + prev[i - 1];
				cnt = 1;
			}
		}
		res += std::to_string(cnt) + prev[prev.size() - 1];
		return res;
	}
};