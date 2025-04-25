#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);



int main() {
	fast
	int n, k;
	std::cin >> n >> k;
	
	std::vector<std::pair<int, int>> prices(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> prices[i].first >> prices[i].second;
	}
	std::vector<int> dp(k + 1, k);
	for (int i = 0; i < prices.size(); i++)
	{
		int a_i = prices[i].first;
		int b_i = prices[i].second;
		for (int j = k; j >= a_i; j--) {
			if (dp[j - a_i] > 0 || j == a_i) {
				dp[j] = std ::max(dp[j], dp[j - a_i] + b_i - a_i);
			}
		}
	}
	std::cout << *max_element(dp.begin(), dp.end()) << '\n';
	return 0;
}
