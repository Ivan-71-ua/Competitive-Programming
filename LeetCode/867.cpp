#include <bits/stdc++.h>

class Solution {
public:
   std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& matrix) {
		std::vector<std::vector<int>> val;
		int n = matrix.size();
		int m = matrix[0].size();
		for (int i = 0; i < m; i++)
		{
			std::vector<int> an;
			for (int j = 0; j < n; j++)
			{
				an.push_back(matrix[j][i]);
			}
			val.push_back(an);
		}
		return val;
	}
};