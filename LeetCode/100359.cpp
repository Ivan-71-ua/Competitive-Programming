#include <bits/stdc++.h>


class Solution {
public:
	int numberOfSubmatrices(std::vector<std::vector<char>>& grid) {
		std::vector<std::vector<std::pair<int, int>>> col(grid.size() + 1, std::vector<std::pair<int, int>>(grid[0].size() + 1));
		int res = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			std::vector<std::pair<int, int>> tmp(grid[0].size() + 1);
			for (int j = 0; j < grid[0].size(); j++)
			{
				tmp[j + 1].first +=  tmp[j].first;
				tmp[j + 1].second +=  tmp[j].second;
				if(grid[i][j] == 'X') {
					tmp[j + 1].first++;
				} 
				if(grid[i][j] == 'Y') {
					tmp[j + 1].second++;
				}
				if(tmp[j + 1].first + col[i][j + 1].first > 0 && tmp[j +1].first + col[i][j + 1].first == tmp[j + 1].second + col[i][j + 1].second) {
					res++;
				}
				col[i + 1][j + 1].first = tmp[j + 1].first + col[i][j + 1].first;
				col[i + 1][j + 1].second = tmp[j + 1].second + col[i][j + 1].second;
			}
			//col[i + 1] = tmp;
		}
		return res;
	}
};