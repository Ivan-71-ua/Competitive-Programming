#include <bits/stdc++.h>



class Solution {
public:
	int minimumArea(std::vector<std::vector<int>>& grid) {
		int x_r = -1;
		int y_r = -1;
		int x_l = 1111;
		int y_l = 1111;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if(grid[i][j]) {
					x_r = std::max(x_r, i);
					y_r = std::max(y_r, j);
					x_l = std::min(x_l, i);
					y_l = std::min(y_l, j);
				}
			}
		}
		return (x_r - x_l + 1) * (y_r - y_l + 1);
	}
};