#include <bits/stdc++.h>




class Solution {
	int dfs(int node, std::vector<std::vector<int>>& graph, int deep, int k) {
		int max = 1;
		std::queue<std::tuple<int, int, int>> q;
		q.push({node, -1, 0});
		while(!q.empty()) {
			auto [cur_node, parent, cur_deep] = q.front();
			q.pop();
			if(cur_deep == k) {
				break;
			}
			for(auto next_node : graph[cur_node]) {
				if(next_node != parent) {
					q.push({next_node, cur_node, cur_deep + 1});
					max++;
				}
			}
		}
		return max;
	}
public:
	std::vector<int> maxTargetNodes(std::vector<std::vector<int>>& edges1, std::vector<std::vector<int>>& edges2, int k) {
		int best = 0, n = edges1.size() + 1, m = edges2.size() + 1;
		std::vector<std::vector<int>> graph1(n);
		std::vector<std::vector<int>> graph2(m);
		for(auto &eg : edges1) {
			graph1[eg[0]].push_back(eg[1]);
			graph1[eg[1]].push_back(eg[0]);
		}
		for(auto &eg : edges2) {
			graph2[eg[0]].push_back(eg[1]);
			graph2[eg[1]].push_back(eg[0]);
		}
		for (int i = 0; i < m; i++) {
			int cur = dfs(i, graph2, 0, k - 1);
			if(cur > best) {
				best = cur;
			}
		}
		std::vector<int> ans(n,0);
		for (int i = 0; i < n; i++) {
			ans[i] = dfs(i, graph1, 0, k) + (k > 0 ? best : 0);
		}
		return ans;
	}
};