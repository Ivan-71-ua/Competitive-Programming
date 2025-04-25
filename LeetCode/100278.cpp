#include <bits/stdc++.h>



class Solution {
public:
	long long numberOfRightTriangles(std::vector<std::vector<long long>>& grid) {
		long long rows = grid.size();
		long long cols = grid[0].size();
		std::vector<long long> rowCounts(rows, 0);
		std::vector<long long> colCounts(cols, 0);
		for (long long r = 0; r < rows; r++) {
			for (long long c = 0; c < cols; c++) {
				if (grid[r][c] == 1) {
					rowCounts[r]++;
					colCounts[c]++;
				}
			}
		}
		long long totalTriangles = 0;
		for (long long r = 0; r < rows; r++) {
			for (long long c = 0; c < cols; c++) {
				if (grid[r][c] == 1) {
					if (rowCounts[r] > 1 && colCounts[c] > 1) {
						totalTriangles += (rowCounts[r] - 1) * (colCounts[c] - 1);
					}
				}
			}
		}
		return totalTriangles;
	}
};