
#include <bits/stdc++.h>



class Solution {
public:
	std::vector<int> findWordsContaining(std::vector<std::string>& words, char x) {
		std::vector<int> ans;
		for (int i = 0; i < words.size(); i++) {
			if(words[i].find(x) != std::string::npos) {
				ans.push_back(i);
			}
		}
		return ans;
	}
};