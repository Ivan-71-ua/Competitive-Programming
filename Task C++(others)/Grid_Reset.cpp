#include <bits/stdc++.h>
const int MAX_L = 105;
char state;
int n, m, k, q;
int grid[MAX_L][MAX_L];

int get_sum(int x1, int y1, int x2, int y2) {
	int sum = 0;
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			sum += grid[i][j];
		}
	}
	return sum;
}

void operation(int x, int y) {
	std::cout << x << ' ' << y << '\n';
	for (int i = 1; i <= k; i++) {
		grid[x][y] = 1;
		if (state == 'H') {
			y++;
		} else {
			x++;
		}
	}
	int sumRow[MAX_L] = {}, sumCol[MAX_L] = {};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sumRow[i] += grid[i][j];
			sumCol[j] += grid[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (sumCol[j] == n || sumRow[i] == m) {
					grid[i][j] = 0;
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) {
		std::string s;
		std::cin >> n >> m >> k >> q >> s;
		s = " " + s;
		memset(grid, 0, sizeof(grid));
		for (int i = 1; i <= q; i++) {
			state = s[i];
			if (state == 'H') {
				int row = -1;
				for (int j = 1; j <= n; j++) {
					if (get_sum(j, 1, j, k) == 0) {
						row = j;
						if (get_sum(j, 1, j, m) == m - k) break;
					}
				}
				operation(row, 1);
			} else {
				int col = -1;
				for (int j = 1; j <= m; j++) {
					if (get_sum(1, j, k, j) == 0) {
						col = j;
						if (get_sum(1, j, n, j) == n - k) break;
					}
				}
				operation(1, col);
			}
		}
	}
	return 0;
}