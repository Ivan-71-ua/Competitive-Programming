#include <bits/stdc++.h>
#define int long long
const int MOD = 998244353;

int brute_force(int n) {
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum = (sum + n % (i * i)) % MOD;
	}
	return sum;
}

int main() {
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		std::cout << brute_force(n) << "\n";
	}
	return 0;
}
