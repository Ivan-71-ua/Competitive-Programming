
#include <bits/stdc++.h>



class Solution {
	int dfs(int node, int parent, std::vector<std::vector<int>>& graph, int deep, std::vector<bool> &color) {
		int res = 1 - deep % 2;
		color[node] = deep % 2;
		for(auto next: graph[node]) {
			if(next != parent) {
				res += dfs(next, node, graph, deep + 1, color);
			}
		}
		return res;
	}
public:
	std::vector<int> maxTargetNodes(std::vector<std::vector<int>>& edges1, std::vector<std::vector<int>>& edges2) {
		std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);      
      std::cout.tie(nullptr);
      int n = edges1.size() + 1, m = edges2.size() + 1;
		std::vector<std::vector<int>> adj(n), adj2(m);
		std::vector<bool> color1(n), color2(m);
		for(auto eg: edges1) {
			adj[eg[0]].push_back(eg[1]);
			adj[eg[1]].push_back(eg[0]);
		}
		for(auto eg: edges2) {
			adj2[eg[0]].push_back(eg[1]);
			adj2[eg[1]].push_back(eg[0]);
		}
		int odd1 = dfs(0, -1, adj, 0, color1);
		int even1 = n - odd1;
		int odd2 = dfs(0, -1, adj2, 0, color2);
		int even2 = m - odd2;
		std::vector<int> ans(n);
		for (int i = 0; i < n; i++) {
			if(color1[i]) {
				ans[i] = even1 + std::max(odd2, even2);
			} else {
				ans[i] = odd1 + std::max(odd2, even2);
			}
		}
		return ans;
	}
};