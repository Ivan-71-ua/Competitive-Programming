#include <bits/stdc++.h>



class Solution {
public:
	long long maxMatrixSum(std::vector<std::vector<int>>& matrix) {
		int n = matrix.size();
		long long sum_p = 0;
		long long neg = 0;
		int mins = INT32_MAX;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if(matrix[i][j] < 0) {
					neg++;
				}
				mins = std::min(mins, abs(matrix[i][j]));
				sum_p += abs(matrix[i][j]);
			}
		}
       // std::cout << mins <<'\n';
		if(neg & 1) {
			return sum_p - mins * 2;
		}
		return sum_p;
	}
};