#include <bits/stdc++.h>

#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main() {
	int t;
	std::cin >> t;
	while(t--) {
		int n, p;
		std::cin >> n >> p;
		std::vector<int> proj(p);
		for (int i = 0; i < p; i++) {
			std::cin >> proj[i];
		}
		std::stable_sort(proj.begin(), proj.end(), std::greater<>());
		int res = 0;
		int k = std::min(n, p);
		for (int i = 0; i < k; i++) {
				res += proj[i];
		}
		std::cout << res << '\n';
	}
}
