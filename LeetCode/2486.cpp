#include <bits/stdc++.h>

class Solution {
public:
	int appendCharacters(std::string s, std::string t) {
		int i = 0;
		int j = 0;
		while(i < s.size() && j < t.size()) {
			if(s[i] == t[j])
				j++;
			i++;
		}
		return t.size() - j - 1;
	}
};