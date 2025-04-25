#include <bits/stdc++.h>

class Solution {
public:
	std::vector<std::string> commonChars(std::vector<std::string>& words) {
		std::vector<int> alh(26, INT32_MAX);
		for (auto word: words)
		{
			std::vector<int> tmp(26);
			for (auto chr: word)
			{
				tmp[chr - 'a']++;
			}
			for (int i = 0; i < 26; i++)
			{
				alh[i] = std::min(alh[i], tmp[i]);
			}
		}
		std::vector<std::string> res;
		std::string k;
		for (int i = 0; i < 26; i++)
		{
			k = 'a' + i;
			for (int j = 0; j < alh[i]; j++)
			{
				res.push_back(k);
			}
		}
		return res;
	}
};