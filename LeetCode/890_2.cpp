#include <bits/stdc++.h>



class Solution {
public:
	std::vector<std::string> findAndReplacePattern(std::vector<std::string>& words, std::string pattern) {
		std::vector<std::string> ans;
		for (int i = 0; i < words.size(); i++)
		{
			bool is = true;
			std::vector<int> bic1(26);
			std::vector<int> bic2(26);
			for (int j = 0; j < pattern.size(); j++)
			{
				if(bic1[pattern[j] - 'a'] != bic2[words[i][j]- 'a']) {
					is = false;
					break;
				}
				bic1[pattern[j] - 'a'] = j + 1;
				bic2[words[i][j] - 'a'] = j + 1;
			}
			if(is) {
				ans.push_back(words[i]);
			}
		}
		return ans;
	}
};