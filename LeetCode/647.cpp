#include <bits/stdc++.h>

class Solution {
public:
   int countSubstrings(std::string s) {
		int res = 0;
		for (int i = 0; i < s.size(); i++)
		{
			int r, l;
			r = l = i;
			while(r < s.size() && l >= 0 && s[r] == s[l]) {
				res++;
				r++;
				l--;
			}
			l = i;
			r = i + 1;
			while(r < s.size() && l >= 0 && s[r] == s[l]) {
				res++;
				r++;
				l--;
			}
		}
		return res;
	}
};