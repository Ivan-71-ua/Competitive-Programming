#include <bits/stdc++.h>


class Solution {
public:
	int balancedStringSplit(std::string s) {
		int ans = 0;
		int L = 0;
		for (auto ch: s)
		{
			if(ch == 'L') {
				L++;
			} else {
				L--;
			}
			if(L == 0)
				ans++;
		}
		return ans;
	}
};