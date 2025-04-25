#include <bits/stdc++.h>



class Solution {
	bool can_put(int a_x, int a_y, std::vector<int> &row_col) {
		if(row_col[a_x] != -1)
			return false;
		for (int i = 0; i < row_col.size(); i++)
		{
			if(row_col[i] == a_y)
				return false;
			if(row_col[i] != -1 && abs(a_x - i) == abs(a_y - row_col[i]))
				return false;
		}
		return true; 
	}
	void all_comb(int x,int k, int &ans, std::vector<int> &row_col, int n) {
		if(k == n) {
			ans++;
			return;
		}
		for (int i = 0; i < n; i++)
		{
			if(can_put(x, i, row_col)) {
				row_col[x] = i;
				all_comb(x + 1, k + 1, ans, row_col, n);
				row_col[x] = -1;
			}
		}
	}
public:
	int totalNQueens(int n) {
		int ans = 0;
		std::vector<int> row_col(n, -1);
		all_comb(0, 0, ans, row_col, n);
		return ans;
	}
};

int main() {
	Solution ans;
	ans.totalNQueens(4);
}