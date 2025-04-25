#include <bits/stdc++.h>


int main() {
	int n, k;
	std::cin >> n >> k;
	std::unordered_set<int> brokenSteps;
	for (int i = 0; i < k; i++) {
		int step;
		std::cin >> step;
		brokenSteps.insert(step);
	}

	std::vector<long long> arr(n + 1, 0);
	arr[0] = 1;

	for (int i = 1; i <= n; i++) {
		if (brokenSteps.find(i) == brokenSteps.end()) {
				for (int j = 1; j <= 3; j++) {
					if (i - j >= 0) {
						arr[i] += arr[i - j];
					}
				}
		} else {
				arr[i] = 0;
		}
	}

	if (arr[n] > 0) {
		std::cout << arr[n] << std::endl;
	} else {
		std::cout << "-1" << std::endl;
	}

}
