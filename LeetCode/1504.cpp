#include <bits/stdc++.h>


class Solution {
public:
	int numSubmat(std::vector<std::vector<int>>& mat) {
		int res = 0, n = mat.size(), m = mat[0].size();
		std::vector<std::vector<int>> row(n, std::vector<int>(m, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(j == 0) {
					row[i][j] = mat[i][j];
				} else {
					row[i][j] = (mat[i][j] == 0) ? 0 : row[i][j - 1] + 1;
				}

				int cur = row[i][j];
				for (int k = i; k > -1; k--) {
					cur = std::min(cur, row[k][j]);
					if(cur == 0) {
						break;
					}
					res += cur;
				}
			}
		}
		return res;
	}
};