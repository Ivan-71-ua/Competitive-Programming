#include <bits/stdc++.h>



class Solution {
public:
	long long minimumSteps(std::string s) {
		long long res = 0;
		int l = 0, r = s.size() - 1;
		while(l < r) {
			if(s[l] == '1' && s[r] == '0') {
				res += r - l;
				r--;
				l++;
			} else {
				if(s[l] == '0')
					l++;
				if(s[r] == '1')
					r--;
			}
		}
		return res;
	}
};