
#include <bits/stdc++.h>

int maxFragments(int n, const std::vector<int>& permutation) {
	int max_value = 0;
	int count_fragments = 0;
	
	for (int i = 0; i < n; i++) {
		max_value = std::max(max_value, permutation[i]);
		if (max_value == i) {
			count_fragments++;
		}
	}
	
	return count_fragments;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> permutation(n);
	
	for (int i = 0; i < n; i++) {
		std::cin >> permutation[i];
	}
	
	std::cout << maxFragments(n, permutation) << std::endl;
	return 0;
}
