#include <bits/stdc++.h>


class Solution {
public:
	bool isToeplitzMatrix(std::vector<std::vector<int>>& matrix) {
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				if(i +1 < matrix.size() && j + 1 < matrix[0].size() && matrix[i][j] != matrix[i +1][j +1]) {
					return false;
				}
			}
		}
		return true;
	}
};