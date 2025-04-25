#include <bits/stdc++.h>



int main() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> date(k);
	for (int i = 0; i < k; i++) {
		std::cin >> date[i];
	}
	std::stable_sort(date.begin(), date.end());
	int way = n - date[k - 1] + date[0];
	for (int i = 1; i < k; i++) {
		way = std::max(way, date[i] - date[i - 1]);
	}
	std::cout << std::fixed << std::setprecision(1);
	std::cout << way / 2.0;
}
