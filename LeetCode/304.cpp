#include <bits/stdc++.h>

class NumMatrix {
	std::vector<std::vector<int>> sum_p;  
public:
   NumMatrix(std::vector<std::vector<int>>& matrix) {
		sum_p.resize(matrix.size() + 2, std::vector<int>(matrix[0].size() + 2, 0));
		for (int i = 0; i < matrix.size(); i++)
		{
			int sum = 0;
			for (int j = 0; j < matrix[0].size(); j++)
			{
				sum += matrix[i][j];
				sum_p[i + 1][j + 1] = sum;
				sum_p[i + 1][j + 1] += sum_p[(i + 1) - 1][j + 1];
			}
		}
   }
   
   int sumRegion(int row1, int col1, int row2, int col2) {
		return sum_p[row2 + 1][col2 + 1] - sum_p[(row1 + 1) - 1][col2 + 1] - (sum_p[row2 + 1][(col1 + 1) - 1] - sum_p[(row1 + 1) - 1][(col1 + 1) - 1]);
	}
};