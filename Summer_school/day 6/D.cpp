#include <bits/stdc++.h>


const int MAXN = 1000000;

int main() {
	int n;
	std::cin >> n;
	std::vector<int> A(n);
	std::vector<int> freq(MAXN + 1, 0);
	std::vector<bool> is_divisible(MAXN + 1, false);
	for (int i = 0; i < n; i++) {
		std::cin >> A[i];
		freq[A[i]]++;
	}

	for (int i = 1; i <= MAXN; i++) {
		if (freq[i] > 0) {
			for (int j = 2 * i; j <= MAXN; j += i) {
				if (freq[j] > 0) {
					is_divisible[j] = true;
				}
			}
		}
	}

	int result = 0;
	for (int i = 1; i <= MAXN; i++) {
		if (freq[i] == 1 && !is_divisible[i]) {
			result += freq[i];
		}
	}
	std::cout << result << "\n";
	return 0;
}
