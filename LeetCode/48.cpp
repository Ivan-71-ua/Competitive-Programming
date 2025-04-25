#include <bits/stdc++.h>



class Solution {
public:
	void rotate(std::vector<std::vector<int>>& matrix) {
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = i + 1; j < matrix[0].size(); j++)
			{
				std::swap(matrix[i][j], matrix[j][i]);
			}
		}
		for (int i = 0; i < matrix.size(); i++)
		{
			int s = 0, f = matrix[0].size() - 1;
			while(s < f) {
				std::swap(matrix[i][s], matrix[i][f]);
				s++;
				f--;
			}
		}
	}
};