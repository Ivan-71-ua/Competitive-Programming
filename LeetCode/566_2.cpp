#include <bits/stdc++.h>

class Solution {
public:
   std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& mat, int r, int c) {
      if(r * c < mat.size() * mat[0].size() || r * c > mat.size() * mat[0].size() || r == mat.size() && c == mat[0].size()) {
			return mat;
		}
		std::vector<std::vector<int>> res(r, std::vector<int>(c));
		for (int i = 0; i < r * c; i++)
		{
			res[i / c][i % c] = mat[i / mat[0].size()][i % mat[0].size()];
		}
		return res;
	}
};