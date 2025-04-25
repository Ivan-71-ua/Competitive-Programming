#include <bits/stdc++.h>

class Solution {
	void full_way(int cur_x, int cur_y, int cur_on_way, int on_way, int &ans, std::vector<std::vector<int>> &grid) {
		if(cur_x >= grid.size() || cur_y >= grid[0].size() || cur_x < 0 || cur_y < 0 || grid[cur_x][cur_y] == -1) {
			return;
		}
		if(grid[cur_x][cur_y] == 2 && cur_on_way == on_way) {
			ans++;
			return;
		}
		if(grid[cur_x][cur_y] == 0)
			cur_on_way++;
		int tmp = grid[cur_x][cur_y];
		grid[cur_x][cur_y] = -1;
		full_way(cur_x + 1, cur_y, cur_on_way, on_way, ans, grid);
		full_way(cur_x, cur_y + 1, cur_on_way, on_way, ans, grid);
		full_way(cur_x - 1, cur_y, cur_on_way, on_way, ans, grid);
		full_way(cur_x , cur_y - 1, cur_on_way, on_way, ans, grid);
		grid[cur_x][cur_y] = tmp;
	}
public:
	int uniquePathsIII(std::vector<std::vector<int>>& grid) {
		//std::vector<std::vector<bool>> used(grid.size(), std::vector<bool>(grid[0].size()));
		int on_way = 0;
		int x, y;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if(grid[i][j] == 0)
					on_way++;
				if(grid[i][j] == 1){
					x = i;
					y = j;
				}
			}
		}
		int ans = 0;
		full_way(x, y, 0, on_way, ans, grid);
		return ans;
	}
};