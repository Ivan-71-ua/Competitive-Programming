#include <bits/stdc++.h>


class Solution {
public:
	std::string shortestCompletingWord(std::string licensePlate, std::vector<std::string>& words) {
		int sizes = INT16_MAX;
		std::string ans;
		std::unordered_map<char, int> alf;
		for (int i = 0; i < licensePlate.size(); i++)
		{
			if(isalpha(licensePlate[i])) {
				alf[tolower(licensePlate[i])]++;
			}
		}
		for (int i = 0; i < words.size(); i++)
		{
			for (int j = 0; j < words[i].size(); j++)
			{
				words[i][j] = tolower(words[i][j]);
			}
			bool is = true;
			for (auto now: alf)
			{
				if(std::count(words[i].begin(), words[i].end(), now.first) < now.second) {
					is = false;
				}
			}
			if(is) {
				if(sizes > words[i].size()) {
					ans = words[i];
					sizes = words[i].size();
				}
			}
		}
		return ans;
	}
};