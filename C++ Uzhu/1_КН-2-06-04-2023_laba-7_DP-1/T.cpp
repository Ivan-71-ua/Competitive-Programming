#include <bits/stdc++.h>
#define int long long

int32_t main() {
	int n, a, b;
	std::cin >> n >> a >> b;
	std::vector<int> arr(n + 3);
	std::vector<int> dp(n + 3);
	for (int i = 1; i <= n; i++)
	{
		std::cin >> arr[i];
	}
	dp[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + std::min(a * (arr[i] - arr[i - 1]), b);
	}
	std::cout << dp[n];
}