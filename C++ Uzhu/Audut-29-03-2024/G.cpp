#include <bits/stdc++.h>

int main() {
	int l, v, n;
	std::cin >> l >> v >> n;
	std::vector<double> dp(100010, std::numeric_limits<double>::max()); // Инициализация большим числом
	dp[0] = 0;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		std::cin >> a >> b;
		for (int j = mx; j >= 0; j--) {
				if (j + a < 100010 && dp[j] + b < dp[j + a]) // Проверка границ и обновление dp
					dp[j + a] = dp[j] + b;
		}
		mx = std::min(100009, mx + a); // Обновление mx с проверкой на максимально возможный индекс
	}
	double ans = std::numeric_limits<double>::max();
	for (int i = 0; i <= mx; i++) { // Итерация до mx включительно
		if (dp[i] < std::numeric_limits<double>::max()) { // Убедиться, что dp[i] был обновлен
				double temp = l / (double)(v + i) + dp[i]; // Использование double для времени
				ans = std::min(ans, temp);
		}
	}
	std::cout << std::fixed << std::setprecision(6);
	std::cout << ans << std::endl;
}
