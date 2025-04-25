#include <bits/stdc++.h>

class Solution {
public:
   bool isValidSudoku(std::vector<std::vector<char>>& board) {
		bool isidigit[9][9]{};
		bool jisdigit[9][9]{};
		bool ijisdigit[3][3][9]{};
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if(board[i][j] != '.') {
					int d = board[i][j] - '1';
					if(isidigit[i][d]) {
						return false;
					}
					isidigit[i][d] = true;
					if(jisdigit[j][d]) {
						return false;
					}
					jisdigit[j][d] = true;
					if(ijisdigit[i/3][j/3][d]) {
						return false;
					}
					ijisdigit[i / 3][j / 3][d] = true;
				}
			}
			
		}
		return true;
	}
};

int main() {
	
}