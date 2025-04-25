#include <bits/stdc++.h>


class Solution {
const int MODULO = 1'000'000'007;


long long binomial_coefficient(int n, int k) {
	std::vector<std::vector<long long>> C(n + 1, std::vector<long long>(k + 1, 0));
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= std::min(i, k); ++j) {
				if (j == 0 || i == j) {
					C[i][j] = 1;
				} else {
					C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MODULO;
				}
		}
	}
	return C[n][k];
}


int count_stable_arrays(int zero, int one, int limit) {
	int total_elements = zero + one;

	
	long long total_permutations = binomial_coefficient(total_elements, zero);

	long long stable_count = total_permutations;

	std::vector<int> initial(zero + one, 1);
	std::fill_n(initial.begin(), zero, 0);

	do {
		bool valid = true;
		for (int len = limit + 1; len <= total_elements && valid; ++len) {
				for (int start = 0; start <= total_elements - len; ++start) {
					bool all_same = std::all_of(
						initial.begin() + start,
						initial.begin() + start + len,
						[&](int val) { return val == initial[start]; }
					);
					if (all_same) {
						valid = false;
						break;
					}
				}
		}
		if (!valid) {
				stable_count = (stable_count - 1 + MODULO) % MODULO;
		}
	} while (std::next_permutation(initial.begin(), initial.end()));

	return stable_count;
}
public:
	int numberOfStableArrays(int zero, int one, int limit) {
		return count_stable_arrays(zero, one, limit);
	}
};