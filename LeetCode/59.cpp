#include <bits/stdc++.h>




class Solution {
public:
	std::vector<std::vector<int>> generateMatrix(int n) {
		int  sq = n * n;
		int k = 1;
		std::vector<std::vector<int>> ans(n, std::vector<int>(n, 0));
		std::vector<int> dx = {0, 1, 0, -1};
		std::vector<int> dy = {1, 0, -1, 0};
		int dir = 0;
		int i = 0, j = 0;
		while(k <= sq) {
			ans[i][j] = k;
			k++;
			int ni = i + dx[dir];
			int nj = j + dy[dir];
			if(ni < 0 || ni >= n || nj < 0 || nj >= n || ans[ni][nj] != 0) {
				dir = (dir + 1) % 4;
				ni = i + dx[dir];
				nj = j + dy[dir];
			}
			i = ni;
			j = nj;
		}
		return ans;
	}
};