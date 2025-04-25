#include <bits/stdc++.h>


class Solution {
	int cnt = 0;
public:
	int regionsBySlashes(std::vector<std::string>& grid) {
		int n = grid.size();
		int dts = n + 1;
		std::vector<int> parent(dts * dts);
		std::vector<int> size(dts * dts);
		for (int i = 0; i < parent.size(); i++)
		{
			set_union(i, parent, size);
		}
		for (int i = 0; i < dts; i++)
		{
			for (int j = 0; j < dts; j++)
			{
				if(i == 0 || j == 0 || i == n || j == n) {
					int cell = i * dts + j;
					make_union(0, cell, parent, size);
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if(grid[i][j] == '\\') {
					int cell1 = i * dts + j;
					int cell2 = (i + 1) * dts + j + 1;
					make_union(cell1, cell2, parent, size);
				} else if(grid[i][j] == '/') {
					int cell1 = (i + 1) * dts + j;
					int cell2 = i * dts + j + 1;
					make_union(cell1, cell2, parent, size);
				}
			}
		}
		return cnt;
	}
	void set_union(int x, std::vector<int> &parent, std::vector<int> &size) {
		parent[x] = x;
		size[x] = 1;
	}
	void make_union(int x, int y, std::vector<int> &parent, std::vector<int> &size) {
		int px = find(x, parent);
		int py = find(y, parent);
		if(px == py)
			cnt++;
		else {
			if(size[px] < size[py])
				std::swap(px, py);
			parent[py] = px;
			size[px] += size[py];
		}
	}
	int find(int x, std::vector<int> parent) {
		if(parent[x] != x) {
			return parent[x] = find(parent[x], parent);
		}
		return parent[x];
	}
};