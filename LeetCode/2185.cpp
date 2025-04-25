#include <bits/stdc++.h>




class Solution {
	bool find(std::string s1, std::string s2) {
		int i = 0;
		while (i < s2.size())
		{
			if(s1[i] != s2[i])
				return false;
			i++;
		}
		
		return true;
	}
public:
	int prefixCount(std::vector<std::string>& words, std::string pref) {
		int res = 0;
		for (int i = 0; i < words.size(); i++) {
			if(words.size() < pref.size()) {
				continue;
			}
			if(find(words[i], pref)) {
				res++;
			}
		}
		return res;
	}
};