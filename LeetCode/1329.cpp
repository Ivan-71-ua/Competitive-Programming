#include <bits/stdc++.h>


class Solution {
public:
	std::vector<std::vector<int>> diagonalSort(std::vector<std::vector<int>>& mat) {
		std::unordered_map<int, std::priority_queue<int, std::vector<int>, std::greater<int>>> dig;
		for (int i = 0; i < mat.size(); i++)
		{
			for (int j = 0; j < mat[0].size(); j++)
			{
				dig[i - j].push(mat[i][j]);
			}
		}
		for (int i = 0; i < mat.size(); i++)
		{
			for (int j = 0; j < mat[0].size(); j++)
			{
				mat[i][i] = dig[i - j].top();
				dig[i - j].pop();
			}
		}
		return mat;
	}
};