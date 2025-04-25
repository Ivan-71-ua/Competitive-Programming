#include <bits/stdc++.h>




class Solution {
public:
	int minimumCost(std::string target, std::vector<std::string>& words, std::vector<int>& costs) {
		int n = target.length();
		std::vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0; // початковий стан, створити порожній рядок не коштує нічого
		for (int i = 0; i < n; ++i) {
			if (dp[i] == INT_MAX) continue; // якщо dp[i] не був оновлений, пропускаємо
			for (int j = 0; j < words.size(); ++j) {
					int word_len = words[j].length();
					if (i + word_len <= n && target.substr(i, word_len) == words[j]) {
						dp[i + word_len] = std::min(dp[i + word_len], dp[i] + costs[j]);
					}
			}
		}
		return dp[n] == INT_MAX ? -1 : dp[n];
	}
};