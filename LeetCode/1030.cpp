#include <bits/stdc++.h>



class Solution {
public:
	std::vector<std::vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
		std::vector<std::vector<int>> res;
		res.reserve(rows * cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				res.push_back({i, j});
			}
		}
		auto cmp = [rCenter, cCenter](const std::vector<int> &a, const std::vector<int> &b)
		{
			return abs(rCenter - a[0]) + abs(cCenter - a[1]) < abs(rCenter - b[0]) + abs(cCenter - b[1]);
		};
		std::stable_sort(res.begin(), res.end(), cmp);
		return res;
	}
};