#include <bits/stdc++.h>
struct pos {
	long long x, y, coins;
};

// Функція порівняння для сортування
bool compare(const pos& a, const pos& b) {
	return a.y < b.y;
}

int maxCoins(const std::vector<pos>& platforms, int v, int g) {
	int n = platforms.size();
	std::vector<int> opt(n, 0);
	int res = 0;
	for (int i = n - 1; i >= 0; --i) {
		opt[i] = platforms[i].coins;
		for (int j = i + 1; j < n; ++j) {
				// Перевіряємо, чи можливий стрибок
				if ((g * (platforms[i].x - platforms[j].x) * (platforms[i].x - platforms[j].x) <=
					(platforms[j].y - platforms[i].y) * 2 * v * v) && (opt[j] + platforms[i].coins > opt[i])) {
					opt[i] = opt[j] + platforms[i].coins;
				}
		}
		if (opt[i] > res) {
				res = opt[i];
		}
	}
	return res;
}

int main() {
	int n, v, g;
	while (std::cin >> n >> v >> g) {
		std::vector<pos> platforms(n);
		for (int i = 0; i < n; ++i) {
				std::cin >> platforms[i].x >> platforms[i].y >> platforms[i].coins;
		}
		// Сортуємо платформи за зростанням їх координати y
		std::sort(platforms.begin(), platforms.end(), compare);
		int result = maxCoins(platforms, v, g);
		std::cout << result << std::endl;
	}
}
