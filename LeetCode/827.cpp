#include <bits/stdc++.h>

class Solution {
	std::vector<int> xs{-1, 1, 0, 0}, ys{0, 0, -1, 1};

	void dfs(int x, int y, std::vector<std::vector<int>>& grid, int n, int island_id, int &cur_size) {
		if (x < 0 || y < 0 || x >= n || y >= n || grid[x][y] != 1) return;
		
		grid[x][y] = island_id;
		cur_size++;
		
		for (int i = 0; i < 4; i++) {
			int nx = x + xs[i], ny = y + ys[i];
				dfs(nx, ny, grid, n, island_id, cur_size);
		}
	}

public:
	int largestIsland(std::vector<std::vector<int>>& grid) {
		int n = grid.size();
		std::vector<int> island_size(n * n);
		int island_id = 2;
		bool has_zero = false;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1) {
					int cur_size = 0;
					dfs(i, j, grid, n, island_id, cur_size);
					island_size[island_id] = cur_size;
					island_id++;
				} else if (grid[i][j] == 0) {
					has_zero = true;
				}
			}
		}

		if (!has_zero) return n * n;

		int max_area = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 0) {
					std::unordered_set<int> visited;
					int potential_area = 1;

					for (int k = 0; k < 4; k++) {
						int nx = i + xs[k], ny = j + ys[k];
						if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] > 1) {
							int island_id = grid[nx][ny];
							if (visited.insert(island_id).second) {
								potential_area += island_size[island_id];
							}
						}
					}
					max_area = std::max(max_area, potential_area);
				}
			}
		}

		return max_area;
	}
};