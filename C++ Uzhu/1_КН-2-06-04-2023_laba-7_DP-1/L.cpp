#include <bits/stdc++.h>


int main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1);
	std::vector<int> dp(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin() + 1, a.begin() + n + 1);
	dp[2] = a[2] - a[1];
	dp[3] = a[3] - a[1];
	for (int i = 4; i <= n; i++) {
		dp[i] = std::min(dp[i - 1], dp[i - 2]) + a[i] - a[i - 1];
	}
	std::cout << dp[n] << '\n';
}
