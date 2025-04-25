#include <bits/stdc++.h>

class Solution {
	class Find_Union
	{
	private:
		std::vector<int> parent;
		std::vector<int> rank;
	public:
		Find_Union(int n) {
			parent.resize(n);
			rank.resize(n);
			for (int i = 0; i < n; i++)
			{
				parent[i] = i;
				rank[i] = 1;
			}
		}
		int find(int x) {
			if(parent[x] != x) {
				return parent[x] = find(parent[x]);
			}
			return x;
		}
		bool make_union(int x, int y) {
			int px = find(x);
			int py = find(y);
			if(px == py) {
				return false;
			} else {
				if(rank[px] < rank[py])
					std::swap(px, py);
				parent[py] = px;
				rank[px] += rank[py];
				return true;
			}
		}
		int max_rank() {
			return *std::max_element(rank.begin(), rank.end());
		}
	};
public:
	std::vector<std::vector<int>> findCriticalAndPseudoCriticalEdges(int n, std::vector<std::vector<int>>& edges) {
		std::vector<std::vector<int>> list_edges;
		for (int i = 0; i < edges.size(); i++)
		{
			list_edges.push_back({edges[i][0], edges[i][1], i, edges[i][2]});
		}
		std::stable_sort(list_edges.begin(), list_edges.end(), [](const std::vector<int>& f, const std::vector<int>& s) {
        		return f[3] < s[3];
    	});
		int max_weight = 0;
		Find_Union unf = Find_Union(n);
		for (auto &edge : list_edges)
		{
			int v1 = edge[0];
			int v2 = edge[1];
			int weight = edge[3];
			if(unf.make_union(v1, v2)) {
				max_weight += weight;
			}
		}
		std::vector<int> critical, pseudo;
		for (int edge = 0; edge < list_edges.size(); edge++)	
		{
			int v1 = list_edges[edge][0];
			int v2 = list_edges[edge][1];
			int idx = list_edges[edge][2];
			int weight = list_edges[edge][3];
			int weight_crit = 0;
			unf = Find_Union(n);
			for (int edge_c = 0; edge_c < list_edges.size(); edge_c++)
			{
				int v1_c = list_edges[edge_c][0];
				int v2_c = list_edges[edge_c][1];
				int idx_c = list_edges[edge_c][2];
				int weight_c = list_edges[edge_c][3];
				if(idx != idx_c && unf.make_union(v1_c, v2_c)) {
					weight_crit += weight_c;
				}
			}
			if(unf.max_rank() != n || weight_crit > max_weight) {
				critical.push_back(idx);
				continue;
			}
			unf = Find_Union(n);
			int weight_pseudo = weight;
			unf.make_union(v1, v2);
			for (auto &edge : list_edges)
			{
				int v1_p = edge[0];
				int v2_p = edge[1];
				int weight_p = edge[3];
				if(unf.make_union(v1_p, v2_p)) {
					weight_pseudo += weight_p;
				}
			}
			if(weight_pseudo == max_weight) {
				pseudo.push_back(idx);
			}
		}
		return {critical, pseudo};
	}
};