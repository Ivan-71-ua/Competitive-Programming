#include <bits/stdc++.h>


class Solution {
public:
	int surfaceArea(std::vector<std::vector<int>>& grid) {
		int area = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid.size(); j++)
			{
				if(grid[i][j] > 0) {
					area += 2;
					if(i - 1 < 0) {
						area += grid[i][j];
					} 
					else {
						if(grid[i][j] > grid[i - 1][j]) {
							area += grid[i][j] - grid[i - 1][j];
						}
					}
					if(j - 1 < 0) {
						area += grid[i][j];
					} 
					else {
						if(grid[i][j] > grid[i][j -1]) {
							area += grid[i][j] - grid[i][j - 1];
						}
					}
					if(i + 1 >= grid.size()) {
						area += grid[i][j];
					} 
					else {
						if(grid[i][j] > grid[i + 1][j]) {
							area += grid[i][j] - grid[i + 1][j];
						}
					} 
					if(j + 1 >= grid.size()) {
						area += grid[i][j];
					} else {
						if(grid[i][j] > grid[i][j + 1]) {
							area += grid[i][j] - grid[i][j + 1];
						}
					}
				}
			}
		}
		return area;
	}
};