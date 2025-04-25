#include <bits/stdc++.h>
#define int long long

const int MOD = 1e9 + 7;

int mod_pow(int base, int exp, int mod) {
	int result = 1;
	while (exp > 0) {
		if (exp % 2 == 1) {
			result = (result * base) % mod;
		}
		base = (base * base) % mod;
		exp /= 2;
	}
	return result;
}

int32_t main() {
	int N, K;
	std::cin >> N >> K;

	std::vector<int> gcd_count(K + 1, 0);
	for (int i = K; i >= 1; i--) {
		gcd_count[i] = mod_pow(K / i, N, MOD);
		for (int j = 2 * i; j <= K; j += i) {
			gcd_count[i] = (gcd_count[i] - gcd_count[j] + MOD) % MOD;
		}
	}

	int result = 0;
	for (int i = 1; i <= K; i++) {
		result = (result + i * gcd_count[i] % MOD) % MOD;
	}
	std::cout << result << "\n";
	return 0;
}
