#include <bits/stdc++.h>


class Solution {
public:
	bool canMakeSquare(std::vector<std::vector<char>>& grid) {
		int B = 0;
		int W = 0;
		{
		if(grid[0][0] == 'B')
			B++;
		else
			W++;
		if(grid[0][1] == 'B')
			B++;
		else
			W++;
		if(grid[1][0] == 'B')
			B++;
		else
			W++;
		if(grid[1][1] == 'B')
			B++;
		else
			W++;
		if(B > 2 || W > 2)
			return true;
		}
		B = W = 0;
		{
		if(grid[0][1] == 'B')
		B++;
		else
			W++;
		if(grid[0][2] == 'B')
			B++;
		else
			W++;
		if(grid[1][1] == 'B')
			B++;
		else
			W++;
		if(grid[1][2] == 'B')
			B++;
		else
			W++;
		if(B > 2 || W > 2)
			return true;
		}
		B = W = 0;
		{
		if(grid[1][0] == 'B')
		B++;
		else
			W++;
		if(grid[1][1] == 'B')
			B++;
		else
			W++;
		if(grid[2][0] == 'B')
			B++;
		else
			W++;
		if(grid[2][1] == 'B')
			B++;
		else
			W++;
		if(B > 2 || W > 2)
			return true;
		}
		B = W = 0;
		{
		if(grid[1][1] == 'B')
		B++;
		else
			W++;
		if(grid[1][2] == 'B')
			B++;
		else
			W++;
		if(grid[2][1] == 'B')
			B++;
		else
			W++;
		if(grid[2][2] == 'B')
			B++;
		else
			W++;
		if(B > 2 || W > 2)
			return true;
		}
		return false;
	}
};