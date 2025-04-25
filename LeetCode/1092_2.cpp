#include <bits/stdc++.h>





class Solution {
public:
	std::string shortestCommonSupersequence(std::string str1, std::string str2) {
		int size1 = str1.size();
		int size2 = str2.size();
		std::vector<std::vector<int>> dp(size1 + 1, std::vector<int>(size2 + 1, 0));

		for (int i = 0; i <= size1; i++) dp[i][0] = i;
		for (int j = 0; j <= size2; j++) dp[0][j] = j;

		for (int i = 1; i <= size1; i++) {
			for (int j = 1; j <= size2; j++) {
				if (str1[i - 1] == str2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				} else {
					dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + 1;
				}
			}
		}

		std::string result;
		int i = size1, j = size2;

		while (i > 0 && j > 0) {
			if (str1[i - 1] == str2[j - 1]) {
				result += str1[i - 1];
				i--, j--;
			} else if (dp[i - 1][j] < dp[i][j - 1]) {
				result += str1[i - 1];
				i--;
			} else {
				result += str2[j - 1];
				j--;
			}
		}

		while (i > 0) result += str1[--i];
		while (j > 0) result += str2[--j];

		reverse(result.begin(), result.end());
		return result;
	}
};
