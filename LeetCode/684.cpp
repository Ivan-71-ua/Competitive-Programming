#include <bits/stdc++.h>



class Solution {
public:
	std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
		int n = edges.size() + 1;
		std::vector<int> parent(n);
		std::vector<int> size(n);
		for (int i = 0; i < n; i++)
		{
			union_set(i, parent,size);
		}
		for (auto edge: edges)
		{
			if(!union_make(edge[0], edge[1], parent, size))
				return edge;
		}
		return {};
	}
	void union_set(int x, std::vector<int> &parent, std::vector<int> &size) {
		parent[x] = x;
		size[x] = 1;
	}
	bool union_make(int x, int y, std::vector<int> &parent, std::vector<int> &size) {
		int px = find(x, parent);
		int py = find(y, parent);
		if(px == py)
			return false;
		if(size[px] < size[py])
			std::swap(px, py);
		parent[py] = px;
		size[px] += py;
		return true;
	}
	int find(int x, std::vector<int> &parent) {
		if(parent[x] != x) {
			return parent[x] = find(parent[x], parent);
		}
		return parent[x];
	}
};



int main() {
	Solution ans;
	std::vector<std::vector<int>> ss{{1, 2}, {1, 3}, {2, 3}};
	ans.findRedundantConnection(ss);
}