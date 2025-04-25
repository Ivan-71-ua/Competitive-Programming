#include <bits/stdc++.h>

int main() {
	int m, n;
	std::cin >> m >> n;
	std::vector<std::vector<int>> a(m + 1, std::vector<int>(n + 1, -1));
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			std::cin >> a[m - i + 1][j];
		}
	}
	a[0][1] = 0;
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			a[i][j] = std::max(a[i - 1][j], a[i][j - 1]) + a[i][j];
		}
	}
	int i = m, j = n;
	std::vector<char> pos;
	while (i + j > 2) {
		if (a[i - 1][j] > a[i][j - 1]) {
			pos.push_back('F');
			--i;
		} else {
			pos.push_back('R');
			--j;
		}
	}
	for (int k = pos.size() - 1; k >= 0; --k) {
		std::cout << pos[k];
	}
	std::cout << std::endl;
}
