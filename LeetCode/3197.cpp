
#include <bits/stdc++.h>


class Solution {
	int minimumSum(std::vector<std::vector<int>> &grid, int u, int d, int l, int r) {
		int min_i = grid.size(), max_i = 0;
		int min_j = grid[0].size(), max_j = 0;
		for (int i = u; i <= d; i++) {
			for (int j = l; j <= r; j++) {
					if (grid[i][j] == 1) {
						min_i = std::min(min_i, i);
						min_j = std::min(min_j, j);
						max_i = std::max(max_i, i);
						max_j = std::max(max_j, j);
					}
			}
		}
		return min_i <= max_i ? (max_i - min_i + 1) * (max_j - min_j + 1)
									: INT_MAX / 3;
	}

	std::vector<std::vector<int>> rotate(std::vector<std::vector<int>> &vec) {
		int n = vec.size(), m = vec[0].size();
		std::vector<std::vector<int>> ret(m, std::vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
					ret[m - j - 1][i] = vec[i][j];
			}
		}
		return ret;
	}

	int solve(std::vector<std::vector<int>> &grid) {
		int n = grid.size(), m = grid[0].size();
		int res = n * m;
		for (int i = 0; i + 1 < n; i++) {
			for (int j = 0; j + 1 < m; j++) {
					res =
						std::min(res, minimumSum(grid, 0, i, 0, m - 1) +
										minimumSum(grid, i + 1, n - 1, 0, j) +
										minimumSum(grid, i + 1, n - 1, j + 1, m - 1));
					res = std::min(res, minimumSum(grid, 0, i, 0, j) +
											minimumSum(grid, 0, i, j + 1, m - 1) +
											minimumSum(grid, i + 1, n - 1, 0, m - 1));
			}
		}
		for (int i = 0; i + 2 < n; i++) {
			for (int j = i + 1; j + 1 < n; j++) {
					res = std::min(res, minimumSum(grid, 0, i, 0, m - 1) +
											minimumSum(grid, i + 1, j, 0, m - 1) +
											minimumSum(grid, j + 1, n - 1, 0, m - 1));
			}
		}
		return res;
	}

public:
	int minimumSum(std::vector<std::vector<int>> &grid) {
		auto rgrid = rotate(grid);
		return std::min(solve(grid), solve(rgrid));
	}
};