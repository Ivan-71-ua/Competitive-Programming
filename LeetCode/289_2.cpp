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
				if(board[dx][dy] == 1 || board[dx][dy] == 3)
					cnt++;
			}
			return cnt;
		}
public:
	void gameOfLife(std::vector<std::vector<int>>& board) {
		int n = board.size(), m = board[0].size();
		std::vector<std::vector<int>> tmp(n, std::vector<int>(m, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) {
				int k = neigbors(n, m, board, i, j);
				if(board[i][j] && k > 1 && k < 4)
					board[i][j] = 3;
				else if(!board[i][j] && k == 3)
					board[i][j] = 2;
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) {
				if(board[i][j] == 1)
					board[i][j] = 0;
				else if(board[i][j] == 2 || board[i][j] == 3)
					board[i][j] = 1;
			}
		}
	}
};