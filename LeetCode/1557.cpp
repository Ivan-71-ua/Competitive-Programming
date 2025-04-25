#include <bits/stdc++.h>

class Solution {
	void BFS(int start, std::vector<std::vector<int>>& edges, std::vector<bool> &used) {
		std::queue<int> way;
		way.push(start);
		while(!way.empty()) {
			int node = way.front();
			used[node] = true;
			way.pop();
			for (int i = 0; i < edges[node].size(); i++)
			{
				if(!used[edges[node][i]]) {
					way.push(edges[node][i]);
				}
			}
		}
	}
public:
	std::vector<int> findSmallestSetOfVertices(int n, std::vector<std::vector<int>>& edges) {
		std::vector<int> res;
		std::vector<bool> used(n);
		for (int i = 0; i < edges.size(); i++)
		{
			used[edges[i][1]] = true;
		}
		for (int i = 0; i < n; i++)
		{
			if(!used[i]) {
				res.push_back(i);
			}
		}
		return res;
	}
};