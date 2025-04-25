#include <bits/stdc++.h>





class Solution {
public:
	std::string shiftingLetters(std::string s, std::vector<std::vector<int>>& shifts) {
		int n = s.size();
		std::vector<int>  pref(n + 1);
		
		for (int i = 0; i < shifts.size(); i++)
		{
			int st = shifts[i][0], f = shifts[i][1], d = shifts[i][2];
			if(d == 1) {
				pref[st]--;
				pref[f + 1]++;
			} else {
				pref[st]++;
				pref[f + 1]--;
			}
		}
		for (int i = n - 1; i > -1; i--) {
			pref[i] += pref[i + 1];
		}
		std::string res;
		for (int i = 1; i <= n; i++)
		{
			int k = ((26 + ((s[i-1] - 'a') + pref[i]) % 26) % 26);
			res += (k + 'a');
		}
		return res;
	}
};