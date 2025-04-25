#include <bits/stdc++.h>


class Solution {
public:
	int numRookCaptures(std::vector<std::vector<char>>& board) {
		int x =0;
		int y =0;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if(board[i][j] == 'R') {
					x = i;
					y = j;
					break;
				}
			}
			if(x && y) break;
		}
		int ans = 0;
		for (int i = x + 1; i < 8; i++)
		{
			if(board[i][y] != '.') {
				if(board[i][y] == 'p') {
					ans++;
				}
				break;
			}
		}
		for (int i = x - 1; i > -1; i--)
		{
			if(board[i][y] != '.') {
				if(board[i][y] == 'p') {
					ans++;
				}
				break;
			}
		}
		for (int i = y + 1; i < 8; i++)
		{
			if(board[x][i] != '.') {
				if(board[x][i] == 'p') {
					ans++;
				}
				break;
			}
		}
		for (int i = y - 1; i > -1; i--)
		{
			if(board[x][i] != '.') {
				if(board[x][i] == 'p') {
					ans++;
				}
				break;
			}
		}
		return ans;
	}
};

int main() {
	Solution ans;
	std::vector<std::vector<char>> rr{
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', 'p', '.', '.', '.', '.'},
    {'.', '.', '.', 'R', '.', '.', '.', 'p'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', 'p', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'}
};
	ans.numRookCaptures(rr);
}