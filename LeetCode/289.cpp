
#include <bits/stdc++.h>



class Solution {
	int neigbors(int n , int m, std::vector<std::vector<int>>& board, int x, int y) {
		std::vector<int> xs{-1, -1, -1, 0, 1, 1, 1,   0};
		std::vector<int> ys{-1,  0,  1, 1, 1, 0, -1, -1};
		int cnt = 0;
		for (int i = 0; i < 8; i++)
		{
			int dx = x + xs[i], dy = y + ys[i];
			if(dx < 0 || dy < 0 || dx >= n || dy >= m) {
				continue;
			}
			cnt += board[dx][dy];
		}
		if(board[x][y]) {
			if(cnt > 1 && cnt < 4) {
				return 1;
			}
			return 0;
		}
		return cnt == 3;
	}
public:
	void gameOfLife(std::vector<std::vector<int>>& board) {
		int n = board.size(), m = board[0].size();
		std::vector<std::vector<int>> tmp(n, std::vector<int>(m, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) {
				tmp[i][j] = board[i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) {
				board[i][j] = neigbors(n, m, tmp, i, j);
			}
		}
	}
};