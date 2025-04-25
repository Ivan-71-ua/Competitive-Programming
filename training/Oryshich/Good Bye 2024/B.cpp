

#include <bits/stdc++.h>
#define MAXN 400001

int l[MAXN], r[MAXN], sum[MAXN], cnt[MAXN];

void solve() {
	int n;
	std::cin >> n;

	// Ініціалізація
	for (int i = 1; i <= 2 * n; ++i) {
		sum[i] = cnt[i] = 0;
	}

	// Зчитуємо діапазони
	for (int i = 1; i <= n; ++i) {
		std::cin >> l[i] >> r[i];
		if (l[i] == r[i]) {
			sum[l[i]] = 1;
			cnt[l[i]]++;
		}
	}

	// Підрахунок префіксних сум
	for (int i = 1; i <= 2 * n; ++i) {
		sum[i] += sum[i - 1];
	}

	// Перевіряємо унікальність для кожного діапазону
	for (int i = 1; i <= n; ++i) {
		if (l[i] == r[i]) {
			std::cout << (cnt[l[i]] == 1 ? "1" : "0");
		} else {
			int total_in_range = sum[r[i]] - sum[l[i] - 1];
			std::cout << (total_in_range < r[i] - l[i] + 1 ? "1" : "0");
		}
	}

	std::cout << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
