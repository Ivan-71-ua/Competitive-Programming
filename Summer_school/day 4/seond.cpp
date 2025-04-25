#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);


int main() {
	fast;
	std::string s;
	int n;
	std::cin >> s >> n;
	int m = s.size();
	std::vector<std::vector<int>> dp(m, std::vector<int>(m, 0));
	for (int len = 2; len <= m; ++len) {
		for (int l = 0; l <= m - len; ++l) {
			int r = l + len - 1;
			if (s[l] == s[r]) {
				dp[l][r] = dp[l + 1][r - 1];
			} else {
				dp[l][r] = std::min(dp[l + 1][r], dp[l][r - 1]) + 1;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		int l, r;
		std::cin >> l >> r;
		std::cout << dp[l - 1][r - 1] << ' ';
	}
}
