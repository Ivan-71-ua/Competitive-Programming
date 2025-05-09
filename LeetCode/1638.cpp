
#include <bits/stdc++.h>



class Solution {
public:
	int countSubstrings(std::string s, std::string t) {
		int ans = 0;
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < t.size(); j++) {
				int x = i, y = j, d = 0;
				while (x < s.size() && y < t.size()) {
					if(s[x] != t[y])
						d++;
					if(d == 1)
						ans++;
					if(d == 2) break;
					x++, y++;
				}
			}
		}
		return ans;
	}
};