#include <bits/stdc++.h>


void can_fall(int x, int y, int &prev_y, bool &can, std::vector<std::vector<int>> &grid) {
	if (x == grid.size()) {  
		can = true;
		prev_y = y;  
		return;
	}
	
	if (grid[x][y] == 1 && (y + 1 >= grid[0].size() || grid[x][y + 1] != 1)) {
		return;
	}

	if (grid[x][y] == -1 && (y - 1 < 0 || grid[x][y - 1] != -1)) {
		return;
	}

	prev_y = y;

	if (grid[x][y] == 1) {
		can_fall(x + 1, y + 1, prev_y, can, grid);
	} 
	
	else if (grid[x][y] == -1) {
		can_fall(x + 1, y - 1, prev_y, can, grid);
	}
}

class Solution {
public:
	std::vector<int> findBall(std::vector<std::vector<int>>& grid) {
		int n = grid[0].size();
		std::vector<int> ans(n, -1);  
		for (int i = 0; i < n; i++) {
			bool can = false;
			int col = i;
			can_fall(0, i, col, can, grid);  
			if (can)
				ans[i] = col;  
		}
		return ans;
	}
};


int main() {
	std::vector<std::vector<int>> ss{{1, 1, 1, -1, -1}, {1, 1, 1, -1, -1}, {-1, -1, -1, 1, 1}, {1, 1, 1, 1, -1}, {-1, -1, -1, -1, -1}};
	Solution ans;
	ans.findBall(ss);
}