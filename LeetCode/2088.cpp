#include <bits/stdc++.h>

class Solution {
	int count(std::vector<std::vector<int>> grid) {
		int ans = 0;
		int n = grid.size();
		int m = grid[0].size();
		for (int i = 1; i < n; i++)
		{
			for (int j =  1; j < m -1; j++)
			{
				if(grid[i][j] == 1 && grid[i -1][j] > 0) {
					grid[i][j] = std::min({grid[i - 1][j - 1], grid[i - 1][j], grid[i - 1][j + 1]}) + 1;
					ans += grid[i][j] - 1;
				}
			}
		}
		return ans;
	}
public:
	int countPyramids(std::vector<std::vector<int>>& grid) {
        std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
		int cnt = count(grid);
		std::reverse(grid.begin(), grid.end());
		cnt += count(grid);
		return cnt;
	}
};