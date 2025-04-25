#include <bits/stdc++.h>

	class Solution {
	public:
		long long mostPoints(std::vector<std::vector<int>>& questions) {
			std::vector<long long> dp(questions.size());
			for (int i = questions.size() - 1; i >= 0; i--)
			{
				dp[i] = std::max(((i + 1 + questions[i][1] >= questions.size() ? 0 : dp[i + 1 + questions[i][1]]) + questions[i][0]),
				 ((i + 1 >= questions.size() ? 0 : dp[i + 1])));
			}
			return dp[0];
		}
	};