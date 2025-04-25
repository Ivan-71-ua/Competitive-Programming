#include <bits/stdc++.h>


class Solution {
public:
	int numberOfSubstrings(std::string s) {
		std::vector<int> pref(s.size());
		pref[0] = (s[0] == '1' ? 1 : 0);
		for (int i = 1; i < s.size(); i++)
		{
			pref[i] = pref[i - 1] + (s[i] == '1' ? 1 : 0);
		}
		int ans = 0;
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = i; j < s.size(); j++)
			{
				int ones = pref[j];
				if(i != 0) {
					ones -= pref[i - 1];
				}
				int zero = j - i + 1 - ones;
				if(zero * zero > ones) {
					j += (zero * zero) - ones - 1;
				} else {
					ans++;
					if(zero * zero < ones) {
						int diff = sqrt(ones) - zero;
						int nextj = j + diff;
						if(nextj >= s.size()) {
							ans += s.size() - j - 1;	
						} else {
							ans += diff;
						}
						j = nextj;
					}
				}
			}
		}
		return ans;
	}
};