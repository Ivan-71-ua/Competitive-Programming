#include <bits/stdc++.h>



class Solution {
public:
	std::vector<std::string> findAndReplacePattern(std::vector<std::string>& words, std::string pattern) {
		std::vector<std::string> ans;
		for (int i = 0; i < words.size(); i++)
		{
			std::map<char, char> biect1;
			std::map<char, char> biect2;
			bool is = true;
			for (int j = 0; j < pattern.size(); j++)
			{
				if(biect2.count(pattern[j])) {
					if(biect2[pattern[j]] != words[i][j]) {
						is = false;
						break;
					}
				} else {
					if(biect1.count(words[i][j])) {
						is = false;
						break;
					}
					biect2[pattern[j]] = words[i][j];
					biect1[words[i][j]] = pattern[j];
				}
			}
			if(is) {
				ans.push_back(words[i]);
			}
		}
		return ans;
	}
};