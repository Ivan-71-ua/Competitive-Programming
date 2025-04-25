#include <bits/stdc++.h>



class Solution {
public:
	std::string frequencySort(std::string s) {
		std::vector<std::pair<int, char>> alph(62);
		for (auto ch: s)
		{
			if(ch >= 'a' && ch <= 'z') {
				alph[ch - 'a'].first++;
				alph[ch - 'a'].second = ch;
			} else if(ch >= 'A' && ch <= 'Z') {
				alph[26 + ch - 'A'].first++;
				alph[26 + ch - 'A'].second = ch;
			} else {
				alph[52 + ch - '0'].first++;
				alph[52 + ch - '0'].second = ch;
			}
		}
		std::stable_sort(alph.begin(), alph.end(), std::greater());
		std::string ans;
		for (auto now: alph)
		{
			for (int i = 0; i < now.first; i++) {
				ans += now.second;
			}
		}
		return ans;
	}
};