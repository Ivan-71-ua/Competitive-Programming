
#include <bits/stdc++.h>


class Solution {
public:
	bool canReachCorner(int X, int Y, std::vector<std::vector<int>>& circles) {
		int n = circles.size();
		std::vector<int> parent(n + 2);
		for (int i = 0; i < n + 2; i++)
		{
			parent[i] = i;
		}
		for (int i = 0; i < n; i++) {
			int x = circles[i][0];
			int y = circles[i][1];
			int r = circles[i][2];
			if (y - r >= Y || x - r >= X) {
				continue;
			}
			if (((x > (X + Y) || y > Y) && (x > X || y > X + Y))) {
				continue;
			}
			if(x + r >= X || y - r <= 0) {
				union_set(n, i, parent);
			}
			if(x - r <= 0 || y + r >= Y) {
				union_set(n + 1, i, parent);
			}
			for (int j = 0; j < i; j++)
			{
				long long x1 = circles[j][0];
				long long y1 = circles[j][1];
				long long r1 = circles[j][2];
				if((x - x1) * (x - x1) + (y - y1) * (y - y1) <= (r + r1) * (r + r1)) {
					union_set(i, j, parent);
				}
			}
		}
		return find_parent(n, parent) != find_parent(n + 1, parent);
	}
	void union_set(int x, int y, std::vector<int> &parent) {
		int px = find_parent(x, parent);
		int py = find_parent(y, parent);
		if(px != py) {
			parent[py] = px;
		}
	}
	int find_parent(int x, std::vector<int> &parent) {
		if(parent[x] != x) {
			return parent[x] = find_parent(parent[x], parent);
		}
		return parent[x];
	}
};


int main() {
	Solution ans;
	std::vector<std::vector<int>> circles{{5, 5, 1}};
	ans.canReachCorner(3, 3, circles);
}