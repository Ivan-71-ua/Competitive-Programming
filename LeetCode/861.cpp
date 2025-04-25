#include <bits/stdc++.h>

class Solution {
public:
	int matrixScore(std::vector<std::vector<int>>& grid) {
		for (int i = 0; i < grid.size(); i++)
		{
			if(!grid[i][0]) {
				
				for (int j = 0; j < grid[0].size(); j++)
				{
					grid[i][j] ^= 1;
				}
			}
		}
		for (int i = 0; i < grid[0].size(); i++)
		{
			int count = 0;
			for (int j = 0; j < grid.size(); j++)
			{
				count += grid[j][i];
			}
			if(count < grid.size() - count) {
				
				for (int p = 0; p < grid.size(); p++)
				{
					grid[p][i] ^= 1;
				}
			}
		}
		int res = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if(grid[i][j]) {
					res += (1 << (grid[0].size()- j -1));
				}
			}
		}
		return res;
	}
};