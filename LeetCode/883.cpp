#include <bits/stdc++.h>


class Solution {
public:
	int projectionArea(std::vector<std::vector<int>>& grid) {
		int v1 = 0;
		int v2 = 0;
		int v3 = 0;
		std::vector<int> side1;
		std::vector<int> side2;
		for (int i = 0; i < grid.size(); i++)
		{
			int k = -1;
			for (int j = 0; j < grid[0].size(); j++)
			{
				if(grid[i][j] > 0)
					v1++;
				k = std::max(k, grid[i][j]);
			}
			side1.push_back(k);
		}
		for (int i = 0; i < grid.size(); i++)
		{
			int k = -1;
			for (int j = 0; j < grid[0].size(); j++)
			{
				k = std::max(k, grid[j][i]);
			}
			side2.push_back(k);
		}
		for (auto now: side1)
		{
			v2 += now;
		}
		for (auto now: side2)
		{
			v3 += now;
		}
		return v1 + v2 + v3;
	}
};