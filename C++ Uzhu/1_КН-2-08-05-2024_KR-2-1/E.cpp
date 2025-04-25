#include <bits/stdc++.h>

#define MOD 1000000007
#define MAX 800001
#define int long long

std::vector<int> fact(MAX), factinv(MAX);
int pow(int x, int n, int p) {
	if (n == 0) return 1;
	if (n % 2 == 0) return pow((x * x) % p, n / 2, p);
	return (x * pow(x, n - 1, p)) % p;
}
int inverse(int x, int p) {
	return pow(x, p - 2, p);
}
int Cnk(int n, int k) {
	return ((fact[n] * factinv[k]) % MOD * factinv[n - k]) % MOD;
}
int ways(int n, int m) {
	return Cnk(n + m, m);
}
int32_t main() {
	fact[0] = 1;
	for (int i = 1; i < MAX; i++)
		fact[i] = (fact[i - 1] * i) % MOD;
	factinv[0] = 1;
	for (int i = 1; i < MAX; i++)
		factinv[i] = inverse(fact[i], MOD);
	int tests;
	std::cin >> tests;
	while (tests--) {
		int n, m, k;
		std::cin >> n >> m >> k;
		int res = 0;
		for (int i = 0; i < k; i++) {
				int x, y;
				int p;
				std::cin >> x >> y >> p;
				res = (res + (ways(x - 1, y - 1) * ways(n - x, m - y) % MOD) * p) % MOD;
		}
		std::cout << res << std::endl;
	}
}
