#include <bits/stdc++.h>

class Solution {
public:
   std::string mergeAlternately(std::string word1, std::string word2) {
		std::string ans;
		int r = 0, l = 0;
		while (r < word1.size() && l < word2.size())
		{
			ans += word1[r];
			ans += word2[l];
			r++;
			l++;
		}
		while(r < word1.size()) {
			ans += word1[r];
			r++;
		}
		while(l < word2.size()) {
			ans += word2[l];
			l++;
		}
		return ans;
	}
};