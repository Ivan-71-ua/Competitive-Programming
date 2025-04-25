#include <bits/stdc++.h>




class Solution {
public:
	std::vector<std::string> stringMatching(std::vector<std::string>& words) {
		int n = words.size();
		std::vector<std::string> res;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) {
				if(i == j) continue;
				if(words[j].find(words[i]) != std::string::npos) {
					res.push_back(words[i]);
					break;
				}
			}
		}
		return res;
	}
};