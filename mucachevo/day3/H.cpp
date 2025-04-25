#include <bits/stdc++.h>


int query(int i, int j) {
	std::cout << "? " << i << " " << j << std::endl;
	std::fflush(stdout);
	int product;
	std::cin >> product;
	return product;
}

void solve() {
	std::array<int, 6> numbers = {4, 8, 15, 16, 23, 42};
	std::vector<std::array<int, 6>> permutations;

	do {
		permutations.push_back(numbers);
	} while (std::next_permutation(numbers.begin(), numbers.end()));

	int prod12 = query(1, 2);
	int prod23 = query(2, 3);
	int prod34 = query(3, 4);
	int prod45 = query(4, 5);

	for (const auto &perm : permutations) {
		if (perm[0] * perm[1] == prod12 &&
			perm[1] * perm[2] == prod23 &&
			perm[2] * perm[3] == prod34 &&
			perm[3] * perm[4] == prod45) {
			std::cout << "! ";
			for (int num : perm) {
					std::cout << num << " ";
			}
			std::cout << std::endl;
			std::fflush(stdout);
			return;
		}
	}
}

int main() {
	solve();
	return 0;
}
