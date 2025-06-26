#include <bits/stdc++.h>



class Solution {
public:
	int longestSubsequence(std::string s, int k) {
		int res = 0, n = s.size(), num = 0;
		for (int i = n - 1; i > -1; i--) {
			if(s[i] == '0') {
				res++;
			} else {
				if (n - i - 1 > 32) continue;
				long long tmp = pow(2, n - i - 1);
				if(num + tmp <= k) {
					num += tmp;
					res++;
				}
			}
		}
		return res;
	}
};