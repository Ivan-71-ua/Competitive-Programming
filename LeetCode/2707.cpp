#include <bits/stdc++.h>


class Solution {
public:
	int minExtraChar(std::string s, std::vector<std::string>& dictionary) {
		int n = s.size();
		std::vector<int> dp(n + 1);
		std::map<std::string, int> dict;
		for (auto wr: dictionary)
		{
			dict[wr]++;
		}
		for (int i = 1; i <= n; i++)
		{
			dp[i] = dp[i - 1] + 1;
			for (int j = 0; j < i; j++)
			{
				std::string sub = s.substr(j, i - j);
				if(dict.count(sub)) {
					dp[i] = std::min(dp[i], dp[j]);	
				}
			}
		}
		return dp[n];
	}
};