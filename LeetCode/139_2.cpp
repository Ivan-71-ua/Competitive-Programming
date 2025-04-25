#include <bits/stdc++.h>

class Solution {
public:
   bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
		std::map<std::string, bool> dict;
		for (auto now: wordDict)
		{
			dict[now] = true;
		}
		std::vector<bool> dp(s.size() + 1);
		dp[0] = true;
		for (int i = 1; i <= s.size(); i++)
		{
			for (int j = i - 1; j >= 0 ; j--)
			{
				if(dp[j]) {
					std::string tp = s.substr(j, i - j);
					if(dict.count(tp)) {
						dp[i] = true;
						break;
					}
				}
			}
		}
		return dp[s.size()];
	}
};