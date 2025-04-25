
#include <bits/stdc++.h>



class Solution {
	std::vector<int> parent;
	std::vector<long long> rank;
	std::vector<int> ands;
	int find(int x) {
		if(parent[x] == x) {
			return x;
		}
		return parent[x] = find(parent[x]);
	}
	void unite(int a, int b, int w) {
		int pa = find(a), pb = find(b);
		if(rank[pa] < rank[pb]) {
			std::swap(pa, pb);
		}
		ands[pa] &= w;
		ands[pa] &= ands[pb];
		if(pa == pb) {
			return;
		}
		rank[pa] += rank[pb];
		parent[pb] = pa;
	}
public:
	std::vector<int> minimumCost(int n, std::vector<std::vector<int>>& edges, std::vector<std::vector<int>>& query) {
		parent.resize(n);
		rank.resize(n, 1);
		ands.resize(n, 1048575);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
		for(int i = 0; i < edges.size(); i++) {
			unite(edges[i][0], edges[i][1], edges[i][2]);
		}
		std::vector<int> ans(query.size());
		for (int i = 0; i < query.size(); i++)
		{
			int pa = find(query[i][0]);
			int pb = find(query[i][1]);
			if(pa != pb) {
				ans[i] = -1;
			} else {
				ans[i] = ands[pa];
			}
		}
		return ans;
	}
};