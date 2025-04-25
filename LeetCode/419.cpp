#include <bits/stdc++.h>


class Solution {
	void DFS(int x, int y, std::vector<std::vector<char>>& board) {
		board[x][y] = '.';
		if(x + 1 < board.size() && board[x + 1][y] == 'X') {
			DFS(x + 1, y, board);
		}
		if(x -1 > -1 && board[x -1][y] == 'X') {
			DFS(x - 1, y, board);
		}
		if(y +1 < board[0].size() && board[x][y + 1] == 'X') {
			DFS(x, y + 1, board);
		}
		if(y -1 > -1 && board[x][y-1] == 'X') {
			DFS(x, y - 1, board);
		}
	}
public:
	int countBattleships(std::vector<std::vector<char>>& board) {
		int res = 0;
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if(board[i][j] == 'X') {
					res++;
					DFS(i, j, board);
				}
			}
		}
		return res;
	}
};