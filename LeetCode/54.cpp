#include <bits/stdc++.h>


class Solution {
public:
	std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
		std::vector<int> res {matrix[0][0]};
		matrix[0][0] = 1000;
		int way = 0;
		int cnt = 1;
		int n = matrix.size();
		int m = matrix[0].size();
		std::vector<int> x{0, 1, 0, -1};
		std::vector<int> y{1, 0, -1, 0};
		int cur_x = 0, cur_y = 0;
		while (cnt < n * m)
		{
			bool can = false;
			int dox = x[way], doy = y[way];
			while(cur_x + dox < n && cur_y + doy < m && cur_x + dox > -1 && cur_y + doy > -1 && matrix[cur_x + dox][cur_y + doy] != 1000) {
				cnt++;
				cur_x += dox;
				cur_y += doy;
				res.push_back(matrix[cur_x][cur_y]);
				matrix[cur_x][cur_y] = 1000;
			}
			way = (way + 1) % 4;
		}
		return res;
	}
};

int main() {
	std::vector<std::vector<int>> ss{{3}, {2}};
	Solution ans;
	ans.spiralOrder(ss);
}