#include <bits/stdc++.h>


std::unordered_map<long long, long long> memo;

long long maxCoins(long long n) {
	if (n <= 3) {
		return 1;
	}
	if (memo.count(n)) {
		return memo[n];
	}
return memo[n] = maxCoins(n / 4) * 2;
}

int main() {
	int t;
	std::cin >> t;
	while (t--) {
		long long n;
		std::cin >> n;
		std::cout << maxCoins(n) << '\n';
	}
	return 0;
}
