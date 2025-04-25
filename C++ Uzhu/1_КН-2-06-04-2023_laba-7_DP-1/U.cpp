#include <bits/stdc++.h>
#define int long long

const int MOD = 1000000007;

int32_t main() {
	int n;
	std::cin >> n;
	std::vector<int> dp(1000002);
	dp[0] = 1;
	int cur_s = 1;
	for (int i = 1; i <= 6; i++)
	{
		dp[i] = (1 << (i - 1));
		cur_s += dp[i];
	}
	for (int i = 7; i <= n; i++)
	{
		dp[i] = (2 * dp[i - 1] - dp[i - 7] + MOD) % MOD;
	}
	std::cout << dp[n];
}