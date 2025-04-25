#include <bits/stdc++.h>


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) {
		int n, p, q;
		std::cin >> n >> p >> q;
		std::vector<int> a(n);
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		std::vector<int> y((int)(q / 64) + 2);
		for (int i = 0; i < y.size(); i++) {
			std::cin >> y[i];
		}
		int x = 0;
		int last_answer = 0;
		int l, r;
		for (int i = 0; i < q; i++) {
			if (i % 64 == 0) {
				l = (y[i / 64] + last_answer) % n;
				r = (y[i / 64 + 1] + last_answer) % n;
			} else {
				l = (l + last_answer + 1) % n;
				r = (r + last_answer + 1) % n;
			}
			if (l > r) std::swap(l, r);
			int product = 1;
			for (int j = l; j <= r; j++) {
				product = (product * a[j]) % p;
			}
			last_answer = product;
			x = (product + 1) % p;
		}
		std::cout << x << '\n';
	}
}
