#include <bits/stdc++.h>


class Solution {
public:
	std::vector<std::vector<char>> rotateTheBox(std::vector<std::vector<char>>& boxGrid) {
		int n = boxGrid.size(), m = boxGrid[0].size();
		std::vector<std::vector<char>> res(m, std::vector<char>(n, '.'));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++) {
				res[j][n - i -1] = boxGrid[i][j];
			}
		}
		for (int i = 0; i < n; i++){
			int sp = m - 1;
			for (int j = m - 1; j > -1; j--) {
				if(res[j][i] == '*') {
					sp = j - 1;
				} else if(res[j][i] == '#') {
					std::swap(res[j][i], res[sp][i]);
					sp--;
				}
			}
		}
		return res;
	}
};