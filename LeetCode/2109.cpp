#include <bits/stdc++.h>



class Solution {
public:
	std::string addSpaces(std::string s, std::vector<int>& spaces) {
		std::string ans;
		int k = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if(k < spaces.size() && spaces[k] == i) {
				ans += " ";
				ans += s[i];
				k++;
			} else {
				ans += s[i];
			}
		}
		return ans;
	}
};