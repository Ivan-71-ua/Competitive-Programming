#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::mt19937 rng(228);

void solve() {
	int K, N;
	std::cin >> K >> N;

	for (int store = 0; store < K; ++store) {
		int best_seen = -1;
		int chosen = -1;

		for (int i = 0; i < N; ++i) {
			int a;
			std::cin >> a;

			if (i < N / 4) {
					best_seen = std::max(best_seen, a);
					std::cout << 0 << std::endl;
			} else {
					if (a > best_seen && chosen == -1) {
						std::cout << 1 << std::endl;
						chosen = i;
					} else if (i == N - 1 && chosen == -1) {
						std::cout << 1 << std::endl;
					} else {
						std::cout << 0 << std::endl;
					}
			}
			std::fflush(stdout);
		}
	}
}

int main() {
	solve();
	return 0;
}
