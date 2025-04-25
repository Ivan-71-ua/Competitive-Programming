#include <bits/stdc++.h>
#define int long long

int32_t main() {
	int n;
	std::cin >> n;
	std::vector<int> positions(n);
	for (int i = 0; i < n; i++) {
		std::cin >> positions[i];
	}
	std::vector<int> costs(n);
	for (int i = 0; i < n; i++) {
		std::cin >> costs[i];
	}
	std::vector<int> tolls(n);
	for (int i = 0; i < n; i++) {
		std::cin >> tolls[i];
	}
	std::vector<long long> dp(n);
	dp[0] = tolls[0];
	const long long INF = INFINITY;
	for (int i = 1; i < n; i++) {
		long long minimumCost = INF;
		for (int j = 0; j < i; j++) {
			long long costToReach = costs[j] * (positions[i] - positions[j]) + dp[j];
			if (costToReach < minimumCost) {
				minimumCost = costToReach;
			}
		}
		dp[i] = tolls[i] + minimumCost;
	}
	std::cout << dp[n - 1] << std::endl;
}
