
#include <bits/stdc++.h>



class Solution {
public:
	std::string customSortString(std::string order, std::string s) {
		std::vector<int> alph(26);
		for (auto &&i : s)
		{
			alph[i - 'a']++;
		}
		std::string ans;
		for(auto &&i : order) {
			while(alph[i - 'a'] > 0) {
				alph[i - 'a']--;
				ans += i;
			}
		}
		for (int i = 0; i < 26; i++)
		{
			while(alph[i] > 0) {
				alph[i]--;
				ans += ('a' + i);
			}
		}
		return ans;
	}
};