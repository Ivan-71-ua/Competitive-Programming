#include <bits/stdc++.h>



class Solution {
public:
	int projectionArea(std::vector<std::vector<int>>& grid) {
		int area = 0;
		int max_xz = 0, max_yz=0;
		for(int i = 0; i < grid.size(); i++) {
				for(int j = 0; j < grid.size(); j++) {
					if(max_xz < grid[i][j]) {
						max_xz = grid[i][j];
					}
					if(max_yz < grid[j][i]) {
						max_yz = grid[j][i];
					}
					if(grid[i][j] > 0) {
						area++;
					}
				}
				area += max_xz;
				area += max_yz;
		}
		return area;
	}
};

// for x-y plane => grid[i][j] > 0 --> area + 1;
// for x-z plane => max(grid[0][0], [0][1], ...) + max(grid[1][0], grid[1][1], ....) + ....
// for y-z plane => max([0][0], [1][0], ...) + max([0][1],[1][1], ...) + ....