#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, p;
	std::cin >> n >> p;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int m;
	std::cin >> m;
	std::vector<std::pair<int, int>> queries(m);
	for (int i = 0; i < m; i++) {
		int l, r;
		std::cin >> l >> r;
		queries[i] = {l - 1, r - 1};
	}
	for (int i = 0; i < m; i++) {
		int l = queries[i].first;
		int r = queries[i].second;
		int count = 0;
		for (int j = 1; j < (1 << (r - l + 1)); j++) {
			int sum = 0;
			for (int k = 0; k <= r - l; k++) {
				if (j & (1 << k)) {
					sum += a[l + k];
				}
			}
			if (sum % p == 0) {
				count = (count + 1) % MOD;
			}
		}
		
		std::cout << count << '\n';
	}
}
