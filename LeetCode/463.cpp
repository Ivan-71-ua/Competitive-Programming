#include <bits/stdc++.h>


class Solution {
	public:
		int islandPerimeter(std::vector<std::vector<int>>& grid) {
			int res = 0;
			for (int i = 0; i < grid.size(); i++)
			{
				for (int j = 0; j < grid[0].size(); j++)
				{
					if(grid[i][j] == 1) {
						res += 4;
						if(i - 1 > -1 && grid[i -1][j] == 1)
							res--;
						if(j - 1 > -1 && grid[i][j-1] == 1)
							res--;
						if(i + 1 < grid.size() && grid[i + 1][j] == 1)
							res--;
						if(j + 1 < grid[0].size() && grid[i][j+1] == 1)
							res--;
					}
				}
			}
		return res;
	}
};