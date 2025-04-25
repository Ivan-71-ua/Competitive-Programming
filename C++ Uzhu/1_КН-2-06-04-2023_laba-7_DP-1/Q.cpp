#include <bits/stdc++.h>
#define int long long

int32_t main() {
	int n;
	std::cin >> n;
	std::vector<int> dp(2 * n + 5);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= 2 * n; i++)
	{
		if(i % 2 == 0) 
			dp[i] = dp[i - 2] + dp[i - 3];
		else
			dp[i] = dp[i - 1];
	}
	std::cout << dp[2 * n - 1];
}