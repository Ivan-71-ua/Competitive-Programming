#include <bits/stdc++.h>



int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};


int find_way(int s_x, int s_y, int f_x, int f_y, int n) {
	std::vector<std::vector<int>> dist(n + 1, std::vector<int>(n + 1, INT_MAX));
	dist[s_x][s_y] = 0;

	std::queue<std::pair<int, int>> q;
	q.push({s_x, s_y});

	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		if (x == f_x && y == f_y) {
			return dist[x][y];
		}

		for (int i = 0; i < 8; ++i) {
			int n_x = x + dx[i];
			int n_y = y + dy[i];

			if (n_x >= 1 && n_x <= n && n_y >= 1 && n_y <= n && dist[n_x][n_y] == INT_MAX) {
				dist[n_x][n_y] = dist[x][y] + 1;
				q.push({n_x, n_y});
			}
		}
	}

	return 0; 
}

int main() {
	int n, s_x, s_y, f_x, f_y;
	std::cin >> n >> s_x >> s_y >> f_x >> f_y;
	std::cout << find_way(s_x, s_y, f_x, f_y, n) << '\n';
}
