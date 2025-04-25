#include <bits/stdc++.h>

class Solution {
public:
	bool judgeCircle(std::string moves) {
		int x = 0;
		int y = 0;
		for (int i = 0; i < moves.size(); i++)
		{
			if(moves[i] == 'R')
				x++;
			else if(moves[i] == 'L')
				x--;
			else if(moves[i] == 'U')
				y++;
			else if(moves[i] == 'D'){
				y--;
			}
		}
		return x == y && x == 0;
	}
};