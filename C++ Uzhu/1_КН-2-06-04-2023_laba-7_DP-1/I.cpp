#include <bits/stdc++.h>

int main() {
	int n;
	std::cin >> n;
	if(n == 1)
		std::cout << 2;
	else if(n == 2) std::cout << 4;
	else {
		std::vector<long long> dp(n + 1, 0);
		dp[1] = 2;
		dp[2] = 4;
		for (int i = 3; i <= n; ++i) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		std::cout << dp[n] << std::endl;
	}
}
