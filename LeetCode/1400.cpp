
#include <bits/stdc++.h>





class Solution {
public:
	bool canConstruct(std::string s, int k) {
		std::vector<int> alph(26);
		int ev = 0;
		for (int i = 0; i < s.size(); i++) {
			alph[s[i]]++;
		}
		for (int i = 0; i < 26; i++) {
			if(alph[i] & 1)
				ev++;
		}
		return s.size() <= k && ev <= k;
	}
};