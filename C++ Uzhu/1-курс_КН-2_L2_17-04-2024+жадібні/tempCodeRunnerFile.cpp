#include <bits/stdc++.h>



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
