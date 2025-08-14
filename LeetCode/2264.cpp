#include <bits/stdc++.h>



class Solution {
public:
	std::string largestGoodInteger(std::string num) {
		std::string res = "";
		int n = num.size();
		for (int i = 0; i < n - 2; i++) {
			if(num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
				std::string cur(3, num[i]);
				res = std::max(res, cur);
			}
		}
		return res;
	}
};