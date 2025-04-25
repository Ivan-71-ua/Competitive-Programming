
#include <bits/stdc++.h>


class Solution {
public:
	int minFlips(std::vector<std::vector<int>>& grid) {
		int ans = 0;
		int n = grid.size();
		int m = grid[0].size();
		for (int i = 0; i < n /2; i++)
		{
			for (int j = 0; j < m /2; j++)
			{
				int ones = 0;
				ones += grid[i][j];
				ones += grid[i][m - j - 1];
				ones += grid[n - i - 1][j];
				ones += grid[n - i - 1][m - j - 1];
				ans += std::min(ones, 4 - ones);
			}
			
		}
		int change = 0;
		int pair_ones = 0;
		if(n & 1) {
			int x = n / 2;
			for (int i = 0; i < m / 2; i++)
			{
				if(grid[x][i] != grid[x][m - i -1]) {
					ans++;
					change++;
				} else if(grid[x][i] == grid[x][m - i -1] && grid[x][i] == 1) {
					pair_ones++;
				}
			}
		}
		if(m & 1) {
			int y = m / 2;
			for (int i = 0; i < n / 2; i++)
			{
				if(grid[i][y] != grid[n - i - 1][y]) {
					ans++;
					change++;
				} else if(grid[i][y] == grid[n - i - 1][y] && grid[i][y] == 1) {
					pair_ones++;
				}
			}
		}
		if((pair_ones & 1) && change == 0) {
			ans += 2;
		}
		if((n & 1) && (m & 1) && grid[n / 2][m / 2]) {
			ans++;
		}
		return ans;
	}
};


int main() {
	Solution ans;
	std::vector<std::vector<int>> res{{1}, {1}};
	ans.minFlips(res);
}