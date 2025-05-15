
#include <bits/stdc++.h>

class Solution {
public:
	std::vector<std::string> getLongestSubsequence(std::vector<std::string>& words, std::vector<int>& groups) {
		std::vector<std::string> result;
		int stack = 0;
		result.reserve(words.size());
		for (int i = 0; i < words.size(); i++) {
			if(result.empty()) {
				result.push_back(words[i]);
				stack = 0;
			} else {
				if(groups[stack] != groups[i]) {
					result.push_back(words[i]);
					stack = i;
				}
			}
		}
		return result;
	}
};