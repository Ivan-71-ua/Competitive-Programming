#include <bits/stdc++.h>
#define int long long
const int MOD = 998244353;


int32_t main() {
	int n;
	std::cin >> n;

	std::vector<int> A(n);
	for (int i = 0; i < n; i++) {
		std::cin >> A[i];
	}

	long long result = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			result = (result + std::lcm(A[i], A[j])) % MOD;
		}
	}
	std::cout << result << "\n";
	return 0;
}
