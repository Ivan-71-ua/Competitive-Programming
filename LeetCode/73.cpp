#include <bits/stdc++.h>



class Solution {
public:
	void setZeroes(std::vector<std::vector<int>>& matrix) {
		int n = matrix.size(), m = matrix[0].size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j< m; j++) {
				if(matrix[i][j] == 0) {
					matrix[i][j] = -10000019;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(matrix[i][j] == -10000019) {
					matrix[i][j] = 0;
					for (int k = j + 1; k < m; k++) {
						if(matrix[i][k] == -10000019 ) {
							break;
						}
						matrix[i][k] = 0;
					}
					for (int k = j - 1; k >= 0; k--) {
						if(matrix[i][k] == -10000019 ) {
							break;
						}
						matrix[i][k] = 0;
					}
					for (int k = i + 1; k < n; k++) {
						if(matrix[k][j] == -10000019 ) {
							break;
						}
						matrix[k][j] = 0;
					}
					for (int k = i - 1; k >= 0; k--) {
						if(matrix[k][j] == -10000019 ) {
							break;
						}
						matrix[k][j] = 0;
					}
				}
			}
		}
	}
};