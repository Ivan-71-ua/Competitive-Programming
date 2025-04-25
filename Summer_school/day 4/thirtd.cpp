#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main() {
	fast;
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	for (int i = 1; i < n; i++) {
		if (a[i] <= a[i - 1]) {
			std::cout << "No" << '\n';
			return 0;
		}
	}

	std::vector<bool> dp(1001, false);
	dp[0] = true;  

	for (int i = 0; i < n; i++) {
		//std::cerr << dp[121] << ' ' << dp[347] << ' ' << dp[486] << '\n';

		if (dp[a[i]]) {
			std::cout << "No" << '\n';
			return 0;
		}
		for (int j = 1000; j >= a[i]; j--) {
			if (dp[j - a[i]]) {
				dp[j] = true;
			}
		}
	}
	std::cout << "Yes" << '\n';
	return 0;
}
