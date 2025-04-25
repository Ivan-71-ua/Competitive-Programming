#include <bits/stdc++.h>

class Solution {
public:
	int longestPalindromeSubseq(std::string s) {
		std::string s_revers = s;
		std::reverse(s.begin(), s.end());
		std::vector<std::vector<int>> dp(s.size() + 1, std::vector<int>(s.size() + 1));
		for (int i = 1; i <= s.size(); i++)
		{
			for (int j = 1; j <= s.size(); j++)
			{
				if(s[i - 1] == s_revers[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else {
					dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp.back().back();
	}
};

int main() {
	Solution ans;
	ans.longestPalindromeSubseq("bbbab");
}