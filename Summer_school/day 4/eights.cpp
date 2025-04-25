#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

struct Suitcase {
	int x, y, z;
};

bool canFit(const Suitcase &a, const Suitcase &b) {
	return (a.x < b.x && a.y < b.y && a.z < b.z);
}

int main() {
	fast
	int n;
	std::cin >> n;
	std::vector<Suitcase> suitcases(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> suitcases[i].x >> suitcases[i].y >> suitcases[i].z;
	}

	for (auto &s : suitcases) {
		std::vector<int> dims = {s.x, s.y, s.z};
		std::stable_sort(dims.begin(), dims.end());
		s.x = dims[0];
		s.y = dims[1];
		s.z = dims[2];
	}

	std::stable_sort(suitcases.begin(), suitcases.end(), [](const Suitcase &a, const Suitcase &b) {
		return std::tie(a.x, a.y, a.z) < std::tie(b.x, b.y, b.z);
	});

	std::vector<int> dp(n, 1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (canFit(suitcases[j], suitcases[i])) {
				dp[i] = std::max(dp[i], dp[j] + 1);
			}
		}
	}
	std::cout << *max_element(dp.begin(), dp.end()) << '\n';
}
