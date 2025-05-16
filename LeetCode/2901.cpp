#include <bits/stdc++.h>


class Solution {
	bool check(std::string s1, std::string s2) {
		if(s1.size() != s2.size()) return false;
		int8_t diff = 0;
		for (int i = 0; i < s1.size(); i++) {
			diff += (s1[i] == s2[i]);
		}
		return diff == 1;
	}
public:
	std::vector<std::string> getWordsInLongestSubsequence(std::vector<std::string>& words, std::vector<int>& groups) {
		int n = words.size();
		std::vector<int> dp(n, 1), prev(n, -1);
		int maxlen = 1;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if(groups[i] != groups[j] && check(words[i], words[j]) && dp[i] < dp[j] + 1){
					dp[i] = dp[j] + 1;
					prev[i] = j;
				}
			}
			maxlen = std::max(maxlen, dp[i]);
		}
		std::vector<std::string> res;
		for (int i = 0; i < n; i++) {
			if(dp[i] == maxlen) {
				while(i != -1) {
					res.push_back(words[i]);
					i = prev[i];
				}
				break;
			}
		}
		std::reverse(res.begin(), res.end());
		return res;
	}
};