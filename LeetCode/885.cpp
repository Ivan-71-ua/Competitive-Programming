#include <bits/stdc++.h>



class Solution {
public:
	std::vector<std::vector<int>> spiralMatrixIII(int rows, int cols, int r, int c) {
		std::vector<std::vector<int>> ans;
		std::vector<int> way{0, 1, 0, -1, 0};
		int direction = 0;
		int len_of_direc = 0;	
		ans.push_back({r, c});
		while(ans.size() < rows * cols) {
			if(direction == 0 || direction == 2) {
				len_of_direc++;
			}
			for (int k = 0; k < len_of_direc; k++)
			{
				r += way[direction];
				c += way[direction + 1];
				if(r < rows && r > -1 && c < cols && c > -1) {
					ans.push_back({r, c});
				}
			}
			direction = ++direction % 4;
		}
		return ans;
	}
};