#include <bits/stdc++.h>

#define MAX 65

std::string s;
long long dp[MAX][MAX];

int main() {
	std::cin >> s;
	int n = s.size();
	std::memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++) {
		dp[i][i] = 1;
	}
	for (int len = 1; len < n; len++) {
		for (int i = 0; i + len < n; i++) {
				int j = i + len;
				if (s[i] == s[j])
					dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1;
				else
					dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
		}
	}
	std::cout << dp[0][n-1] << std::endl;
}
