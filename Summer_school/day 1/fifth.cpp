#include <bits/stdc++.h>


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		int max_beauty = 0;
		for (int l = 0; l < n; l++) {
			for (int r = l; r < n; r++) {
				int max_element = a[l];
				int max_index = l;
				for (int i = l; i <= r; i++) {
					if (a[i] > max_element) {
						max_element = a[i];
						max_index = i;
					}
				}
				int beauty = 0;
				for (int i = l; i <= r; i++) {
					if (i != max_index) {
						beauty ^= a[i];
					}
				}
				max_beauty = std::max(max_beauty, beauty);
			}
		}
		std::cout << max_beauty << '\n';
	}
}
