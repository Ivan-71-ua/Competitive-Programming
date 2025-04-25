#include <bits/stdc++.h>



class Solution {
public:
	int countBattleships(std::vector<std::vector<char>>& board) {
		int count=0;
		int m = board.size();
		int n = board[0].size();
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if (board[i][j]=='X'){
					if ((i>0 and board[i-1][j]=='X') or (j>0 and board[i][j-1]=='X')){
						continue;
					}
					
					count++;
				}
			}
		}
		return count;
	}
};