#include <bits/stdc++.h>
#define int long long


const int MAX = 1007;
std::vector<std::vector<int>> dp(MAX, std::vector<int>(MAX));
std::vector<std::vector<int>> hash(MAX, std::vector<int>(MAX, -1));
int n;
std::string s;

int Palind(int i, int j) {
	if (i >= j) return hash[i][j] = 1;
	if (hash[i][j] != -1) return hash[i][j];
	return hash[i][j] = (s[i] == s[j]) && Palind(i+1, j-1);
}

int32_t main() {
	std::cin >> s;
	n = s.length();
	int res = 0;
	for (int len = 1; len < n; len++) {
		for (int i = 0; i + len < n; i++) {
			int j = i + len;
			if (Palind(i, j)) {
				dp[i][j] = 1;
				continue;
			}
			for (int k = i + 1; k < j; k++) {
				if (dp[i][k] && dp[k + 1][j]) {
					dp[i][j] = 1;
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
				res += dp[i][j];
		}
	}
	std::cout << res;;
}
