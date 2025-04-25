#include <bits/stdc++.h>


class Solution {
	int cnt = 0;
	int n, m;
	void dfs(int x, int y, bool &can, std::vector<std::vector<int>>& grid1, std::vector<std::vector<int>>& grid2) {
		if(x >= n || y >= m || x < 0 || y < 0 || !grid2[x][y]){
			return;
		}
		grid2[x][y] = 0;
		if(!grid1[x][y]) {
			can = false;
		}
		dfs(x + 1, y, can, grid1, grid2);
		dfs(x - 1, y, can, grid1, grid2);
		dfs(x, y + 1, can, grid1, grid2);
		dfs(x, y - 1, can, grid1, grid2);
	}
public:
	int countSubIslands(std::vector<std::vector<int>>& grid1, std::vector<std::vector<int>>& grid2) {
		n = grid2.size();
		m = grid2[0].size();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if(grid2[i][j] != 0) {
					bool can = true;
					dfs(i, j, can, grid1, grid2);
					if(can)
						cnt++;
				}
			}
		}
		return cnt;
	}
};