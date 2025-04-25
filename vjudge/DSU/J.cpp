#include <bits/stdc++.h>

const int MOD = 1000000007;

long long mod_pow(long long base, long long exp, long long mod) {
	long long result = 1;
	while (exp > 0) {
		if (exp % 2 == 1) {
			result = (result * base) % mod;
		}
		base = (base * base) % mod;
		exp /= 2;
	}
	return result;
}

int main() {
	int n, m, k;
	std::cin >> n >> m >> k;
	
	if (k == 1 || k > n) {
		std::cout << mod_pow(m, n, MOD) << '\n';
	} else if (k == n) {
		std::cout << mod_pow(m, (n + 1) / 2, MOD) << '\n';
	} else if (k % 2 == 1) {
		std::cout << mod_pow(m, 2, MOD) << '\n';
	} else {
		std::cout << m % MOD << '\n';
	}
	
	return 0;
}
