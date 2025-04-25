#include <bits/stdc++.h>



class Solution {
public:
	int longestPalindrome(std::string s) {
		std::map<char, int> alph;
		for (int i = 0; i < s.size(); i++)
		{
			alph[s[i]]++;
		}
		int res = 0;
		bool is = true;
		for (auto now: alph)
		{
			if(now.second % 2 != 0 && is) {
				res += now.second;
				is = false;
				continue;
			}
			res += now.second - (now.second % 2);
			
		}
		return res;
	}
};