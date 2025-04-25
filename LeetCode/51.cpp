#include <bits/stdc++.h>



class Solution {
   std::vector<std::vector<std::string>> ans;

	bool can(int x, int y, std::vector<int> &pos) {
		for (int i = 0; i < x; i++) {
			if (pos[i] == y || abs(x - i) == abs(y - pos[i])) {
					return false;
			}
		}
		return true;
	}

	void all_comb(int j, int n, std::vector<int> &pos, std::vector<std::string> &cur) {
		if (j == n) { // Якщо ми досягли кінця дошки (всі ферзі розміщені)
			ans.push_back(cur);
			return;
		}
		for (int i = 0; i < n; i++) {
			if (can(j, i, pos)) {
				cur[j][i] = 'Q';
				pos[j] = i;
				all_comb(j + 1, n, pos, cur);
				cur[j][i] = '.';
				pos[j] = -1;
			}
		}
	}

public:
	std::vector<std::vector<std::string>> solveNQueens(int n) {
		std::vector<std::string> cur(n, std::string(n, '.')); 
		std::vector<int> pos(n, -1);  
		all_comb(0, n, pos, cur); 
		return ans;
	}
};
