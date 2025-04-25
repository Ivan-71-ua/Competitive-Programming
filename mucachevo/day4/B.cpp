#include <bits/stdc++.h>

const long long MOD = 1e9 + 7;

long long mod_exp(long long base, long long exp, long long mod) {
	long long result = 1;
	while (exp > 0) {
		if (exp % 2 == 1) result = (result * base) % mod;
		base = (base * base) % mod;
		exp /= 2;
	}
	return result;
}

void solve() {
	int N, Q;
	std::cin >> N >> Q;

	std::vector<int> A(N + 1), B(N + 1);
	for (int i = 1; i <= N; i++) std::cin >> A[i];
	for (int i = 1; i <= N; i++) std::cin >> B[i];

	std::mt19937_64 rng(228);
	long long r = std::uniform_int_distribution<long long>(1, MOD - 1)(rng);

	std::vector<long long> prefixA(N + 1, 1), prefixB(N + 1, 1);
	for (int i = 1; i <= N; i++) {
		prefixA[i] = (prefixA[i - 1] * (r + A[i])) % MOD;
		prefixB[i] = (prefixB[i - 1] * (r + B[i])) % MOD;
	}

	while (Q--) {
		int l1, r1, l2, r2;
		std::cin >> l1 >> r1 >> l2 >> r2;

		long long hashA = prefixA[r1] * mod_exp(prefixA[l1 - 1], MOD - 2, MOD) % MOD;
		long long hashB = prefixB[r2] * mod_exp(prefixB[l2 - 1], MOD - 2, MOD) % MOD;

		if (hashA == hashB) std::cout << "Yes\n";
		else std::cout << "No\n";
	}
}

int main() {
	solve();
	return 0;
}
