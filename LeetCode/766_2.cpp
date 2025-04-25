#include <bits/stdc++.h>


class Solution {
public:
	bool isToeplitzMatrix(std::vector<std::vector<int>>& matrix) {
		for (int i = 0; i < matrix.size(); i++)
		{
			int x = i;
			int y = 0;
			while(x + 1 < matrix.size() && y + 1 < matrix[0].size())
			{
				if(matrix[x][y] != matrix[x +1][y +1]) {
					return false;
				}
				x++;
				y++;
			}
		}
		for (int i = 0; i < matrix[0].size(); i++)
		{
			int x = 0;
			int y = i;
			while(x + 1 < matrix.size() && y + 1 < matrix[0].size())
			{
				if(matrix[x][y] != matrix[x +1][y +1]) {
					return false;
				}
				x++;
				y++;
			}
		}
		return true;
	}
};