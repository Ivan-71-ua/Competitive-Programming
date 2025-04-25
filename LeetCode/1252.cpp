
#include <bits/stdc++.h>


class Solution {
public:
	int oddCells(int m, int n, std::vector<std::vector<int>>& indices) {
		std::vector<std::vector<int>> mat(n, std::vector<int>(m, 0));
		for (int i = 0; i < indices.size(); i++)
		{
			int x = indices[i][0];
			int y = indices[i][1];
			for (int i = 0; i < m; i++)
			{
				mat[x][i]++;
			}
			for (int i = 0; i < n; i++)
			{
				mat[i][y]++;
			}
		}
		int res = 0;
		for (auto &&i : mat)
		{
			for (auto &&j : i)
			{
				res += j & 1;
			}
		}

		return res;
	}
};