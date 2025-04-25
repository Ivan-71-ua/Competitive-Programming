#include <bits/stdc++.h>

class Solution {
public:
	int countBinarySubstrings(std::string s) {
		int res = 0;
		int prevs = 0;
		int curs = 0;
		int curCh = '@';
		for (auto now: s)
		{
			if(now == curCh) {
				curs++;
			} else {
				res += std::min(curs, prevs);
				prevs = curs;
				curs = 1;
				curCh = now;
			}
		}
		res += std::min(curs, prevs);
		return res;
	}
};