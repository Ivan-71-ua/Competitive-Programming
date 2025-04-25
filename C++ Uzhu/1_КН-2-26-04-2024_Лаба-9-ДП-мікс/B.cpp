#include <bits/stdc++.h>
#define MAX_LEN 51

long long dp[MAX_LEN][MAX_LEN][MAX_LEN];

long long countCommonSubsequences(const std::string& a, const std::string& b, const std::string& c) {
	int lenA = a.size(), lenB = b.size(), lenC = c.size();
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = 1; 
	long long result = 0;
	for (int i = 0; i <= lenA; ++i) {
		for (int j = 0; j <= lenB; ++j) {
			for (int k = 0; k <= lenC; ++k) {
				if (dp[i][j][k] > 0) {
					for (char ch = 'a'; ch <= 'z'; ++ch) {
						int x = i < lenA ? a.find(ch, i) : std::string::npos;
						int y = j < lenB ? b.find(ch, j) : std::string::npos;
						int z = k < lenC ? c.find(ch, k) : std::string::npos;
						if (x != std::string::npos && y != std::string::npos && z != std::string::npos) {
							dp[x + 1][y + 1][z + 1] += dp[i][j][k];
						}
					}
					if (i > 0 && j > 0 && k > 0) {
						result += dp[i][j][k];
					}
				}
			}
		}
	}
	return result;
}

int main() {
	std::string s1, s2, s3;
	while (std::getline(std::cin, s1) && std::getline(std::cin, s2) && std::getline(std::cin, s3)) {
		memset(dp, 0, sizeof(dp));
		long long res = countCommonSubsequences(s1, s2, s3);
		std::cout << res << std::endl;
	}
}
