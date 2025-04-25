#include <bits/stdc++.h>
#define MOD 998244353
#define MAXN 200001

int qpow(int a, int x = MOD - 2) {
	int res = 1;
	while (x) {
		if (x & 1) res = 1LL * res * a % MOD;
		a = 1LL * a * a % MOD;
		x >>= 1;
	}
	return res;
}

int a[MAXN], b[MAXN], c[MAXN], d[MAXN];

void solve() {
	int n, q, res = 1;
	std::cin >> n >> q;

	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		c[i] = a[i];
	}

	for (int i = 1; i <= n; ++i) {
		std::cin >> b[i];
		d[i] = b[i];
	}

	std::sort(c + 1, c + n + 1);
	std::sort(d + 1, d + n + 1);

	for (int i = 1; i <= n; ++i) {
		res = 1LL * res * std::min(c[i], d[i]) % MOD;
	}

	std::cout << res << " \n"[q == 0];

	for (int i = 1, op, x; i <= q; ++i) {
		std::cin >> op >> x;

		if (op == 1) { 
			int p = std::upper_bound(c + 1, c + n + 1, a[x]) - c - 1;
			if (c[p] < d[p]) {
				res = 1LL * res * qpow(c[p]) % MOD * (c[p] + 1) % MOD;
			}
			++a[x];
			++c[p];
		} else { 
			int p = std::upper_bound(d + 1, d + n + 1, b[x]) - d - 1;
			if (d[p] < c[p]) {
				res = 1LL * res * qpow(d[p]) % MOD * (d[p] + 1) % MOD;
			}
			++b[x];
			++d[p];
		}

		std::cout << res << " \n"[i == q];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}