#include <bits/stdc++.h>

class Solution {
public:
   std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& mat, int r, int c) {
      if(r * c < mat.size() * mat[0].size() || r * c > mat.size() * mat[0].size()) {
			return mat;
		}
		std::vector<std::vector<int>> res(r, std::vector<int>(c));
		for (int i = r -1; i >= 0; i--)
		{
			for (int j = c -1; j >=0; j--)
			{
				if(mat.back().empty()) {
					mat.pop_back();
				}
				res[i][j] = mat.back().back();
				mat.back().pop_back();
			}
		}
		return res;
	}
};