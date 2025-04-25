
#include <bits/stdc++.h>


class Solution {
	int n, m, cnt;
	void count_islands(int x, int y, std::vector<std::vector<char>>& grid) {
		if(x < 0 || y < 0 || x >= n | y >= m || grid[x][y] == '0') {
			return;
		}
		grid[x][y] = '0';
		count_islands(x + 1, y, grid);
		count_islands(x - 1, y, grid);
		count_islands(x, y + 1, grid);
		count_islands(x, y - 1, grid);
	}
public:
	int numIslands(std::vector<std::vector<char>>& grid) {
		n = grid.size();
		m = grid[0].size();
		cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if(grid[i][j] == '1') {
					cnt++;
					count_islands(i, j, grid);
				}
			}
		}
		return cnt;
	}
};