#include <bits/stdc++.h>


class Solution {
public:
	int maxNumEdgesToRemove(int n, std::vector<std::vector<int>>& edges) {
		std::vector<int> parentA(n + 1);
		std::vector<int> parentB(n + 1);
		std::vector<int> sizeA(n + 1);
		std::vector<int> sizeB(n + 1);
		for (int i = 0; i <= n; i++)
		{
			set_union(i, parentA, sizeA);
			set_union(i, parentB, sizeB);
		}
		int nB = n;
		int nA = n;
		int cnt = 0;
		for (auto now: edges)
		{
			if(now[0] == 3) {
				cnt += (make_union(now[1], now[2], parentA, sizeA, nA) | make_union(now[1], now[2], parentB, sizeB, nB));
			}
		}
		for (auto now: edges)
		{
			if(now[0] == 1) {
				cnt += make_union(now[1], now[2], parentA, sizeA, nA);
			} else if(now[0] == 2) {
				cnt += make_union(now[1], now[2], parentB, sizeB, nB);
			}
		}
		if(nA == nB && nA == 1) {
			return edges.size() - cnt;
		}
		return -1;
	}

	void set_union(int x, std::vector<int> &parent, std::vector<int> &size) {
		parent[x] = x;
		size[x] = 1;
	}
	int make_union(int x, int y, std::vector<int> &parent, std::vector<int> &size, int &edges) {
		int px = find(x, parent);
		int py = find(y, parent);
		if(px != py) {
			if(size[px] < size[py])
				std::swap(px, py);
			parent[py] = px;
			size[px] += size[py];
			edges--;
			return 1;
		}
		return 0;
	}
	int find(int x, std::vector<int> &parent) {
		if(parent[x] != x) {
			return parent[x] = find(parent[x], parent);
		}
		return parent[x];
	}
};