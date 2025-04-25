#include <bits/stdc++.h>
#define int long long

int32_t main() {
	int n;
	std::cin >> n;
	if(n == 1)
		std::cout << 2;
	else if(n == 2)
		std::cout << 3;
	else {
		std::vector<int> dp(n + 5);
		dp[0] = 1;
		dp[1] = 2;
		for (int i = 2; i < n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		std::cout << dp[n - 1] + dp[n - 3];
	}
}