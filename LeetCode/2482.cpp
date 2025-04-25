#include <bits/stdc++.h>

class Solution {
public:
   std::vector<std::vector<int>> onesMinusZeros(std::vector<std::vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		std::vector<int> onesRow;
		std::vector<int> onesCol;
		std::vector<int> zerosRow;
		std::vector<int> zerosCol;	
		for (int i = 0; i < n; i++)
		{
			int sum0 = 0, sum1 = 0;
			for (int j = 0; j < m; j++)
			{
				if(grid[i][j] == 1) {
					sum1++;
				}
				else {
					sum0++;
				}
			}
			onesRow.push_back(sum1);
			zerosRow.push_back(sum0);
		}
		for (int i = 0; i < m; i++)
		{
			int sum0 = 0, sum1 = 0;
			for (int j = 0; j < n; j++)
			{
				if(grid[j][i] == 1) {
					sum1++;
				}
				else {
					sum0++;
				}
			}
			onesCol.push_back(sum1);
			zerosCol.push_back(sum0);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				grid[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
			}
			
		}
		return grid;
	}
};

int main() {
	Solution ans;
	std::vector<std::vector<int>>  grid {{0, 1, 1}, {1, 0, 1}, {0, 0, 1}};
	ans.onesMinusZeros(grid);
	int n = grid.size();
	int m = grid[0].size();
	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				std::cout << grid[i][j];
			}
			std::cout << "\n";
		}
}