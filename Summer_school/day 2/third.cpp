#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define int long long
const int MOD = 1000000009;

int mod_exp(int base, int exp, int mod) {
	int res = 1;
	while (exp > 0) {
		if (exp % 2 == 1) {
			res = (res * base) % mod;
		}
		base = (base * base) % mod;
		exp /= 2;
	}
	return res;
}

int32_t main() {
	fast
	int n, m, k;
	std::cin >> n >> m >> k;
	if (m < k) {
		std::cout << m << '\n';
	} else {
		int max_possible_double_sequences = (n - (n % k)) / k;
		int max_possible_correct_answers_without_full_k_sequences = (n - (n % k)) / k * (k - 1) + n % k;
		int X = std::max(0LL, m - max_possible_correct_answers_without_full_k_sequences);
		int ans = (mod_exp(2, X + 1, MOD) - 2 + MOD) % MOD * k % MOD + (m - X * k) % MOD;
		ans = (ans % MOD + MOD) % MOD; 
		std::cout << ans << '\n';
	}
}
