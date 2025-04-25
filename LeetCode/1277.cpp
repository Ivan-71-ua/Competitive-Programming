#include <bits/stdc++.h>


const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
   int countSquares(std::vector<std::vector<int>>& matrix) {
      if(matrix.size() == 0)
			return 0;
		int res = 0;
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				if(matrix[i][j] == 0) continue;
				else if(i == 0 || j == 0)
					res++;
				else {
					matrix[i][j] += std::min(matrix[i - 1][j - 1], std::min(matrix[i - 1][j], matrix[i][j - 1]));
					res += matrix[i][j];
				}
			}
		}
		return res;
	}
};