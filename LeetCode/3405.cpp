
#include <bits/stdc++.h>

int const MAXV = 1e5 + 5;

class Solution {
	int MOD = 1e9 + 7;
	long long fact[MAXV], invfact[MAXV];

	long long qpow(long long x, long long n) {
		long long res = 1;
		while (n) {
			if (n & 1)
				res = res * x % MOD;
			x = x * x % MOD;
			n >>= 1;
		}
		return res;
	}

	long long comb(long long n, long long k) {
		if (k < 0 || k > n) return 0;
		return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
	}

public:
	int countGoodArrays(int n, int m, int k) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);      
	std::cout.tie(nullptr);
		fact[0] = 1;
		for (int i = 1; i < MAXV; i++) {
			fact[i] = fact[i - 1] * i % MOD;
		}

		invfact[MAXV - 1] = qpow(fact[MAXV - 1], MOD - 2);
		for (int i = MAXV - 1; i > 0; i--) {
			invfact[i - 1] = invfact[i] * i % MOD;
		}

		return comb(n - 1, k) * m % MOD * qpow(m - 1, n - k - 1) % MOD;
	}
};
