


#include <bits/stdc++.h>


class Solution {
	public:
		std::vector<std::vector<char>> rotateTheBox(std::vector<std::vector<char>>& boxGrid) {
			  std::ios::sync_with_stdio(false);
			std::cin.tie(nullptr);
			std::cout.tie(nullptr);
			int n = boxGrid.size(), m = boxGrid[0].size();
			std::vector<std::vector<char>> res(m, std::vector<char>(n, '.'));
			for (int i = 0; i < n; i++){
				int sp = m - 1;
				for (int j = m - 1; j > -1; j--) {
					if(boxGrid[i][j] == '*') {
						res[j][n - i - 1] = boxGrid[i][j];
						sp = j - 1;
					} else if(boxGrid[i][j] == '#') {
						res[sp][n - i -1]	= boxGrid[i][j];
						sp--;
					}
				}
			}
			return res;
		}
	};