#include <bits/stdc++.h>

int main() {
	int N;
	std::cin >> N;
	std::vector<int> L(N), R(N);

	for (int i = 0; i < N; i++) {
		std::cin >> L[i] >> R[i];
	}

	long long min_sum = std::accumulate(L.begin(), L.end(), 0LL);
	long long max_sum = std::accumulate(R.begin(), R.end(), 0LL);


	if (min_sum > 0 || max_sum < 0) {
		std::cout << "No" << std::endl;
		return 0;
	}

	std::vector<int> X = L; 
	long long current_sum = min_sum;

	for (int i = 0; i < N; i++) {
		if (current_sum == 0) {
			break;
		}
		long long diff = R[i] - L[i];
		if (current_sum + diff <= 0) {
			X[i] += diff;
			current_sum += diff;
		} else {
			X[i] -= current_sum;
			current_sum = 0;
		}
	}

	std::cout << "Yes" << std::endl;
	for (int i = 0; i < N; i++) {
		std::cout << X[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
