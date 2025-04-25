#include <bits/stdc++.h>



class Solution {
	int back_track(std::vector<std::vector<int>>& grid, int x ,int y, std::vector<std::vector<bool>> &visited) {
		if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0 ||  visited[x][y]) {
			return 0;
		}
		visited[x][y] = true;
		int way_cost = std::max({back_track(grid, x + 1, y, visited), back_track(grid, x, y + 1, visited), back_track(grid, x - 1, y, visited), back_track(grid, x, y - 1, visited)});
		visited[x][y] = false;
		return grid[x][y] + way_cost;
	}
public:
	int getMaximumGold(std::vector<std::vector<int>>& grid) {
		int gold = 0;
		std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				gold = std::max(gold, back_track(grid, i, j, visited));
			}
		}
		return gold;
	}
};