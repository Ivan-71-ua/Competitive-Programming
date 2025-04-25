#include <bits/stdc++.h>





class Solution {
	std::vector<std::vector<int>> adj;
	std::unordered_map<int, int> bob_w;
	bool dfs(int start, int parent, int time) {
		if(start == 0) {
			bob_w[start] = time;
			return true;
		}
		for(auto next : adj[start]) {
			if(next == parent) continue;
			if(dfs(next, start, time + 1)) {
				bob_w[start] = time;
				return true;
			}
		}
		return false;
	}
public:
	int mostProfitablePath(std::vector<std::vector<int>>& edges, int bob, std::vector<int>& amount) {
		int n = edges.size();
		adj.resize(n);
		for(auto k: edges) {
			int a = k[0], b = k[1];
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		dfs(bob, -1, 0);
		int res = INT32_MIN;
		std::queue<std::vector<int>> q_node_time_parent_profit;
		q_node_time_parent_profit.push({0, 0, -1, amount[0]});
		while(!q_node_time_parent_profit.empty()) {
			auto tmp = q_node_time_parent_profit.front();
			q_node_time_parent_profit.pop();
			int node = tmp[0], time = tmp[1], parent = tmp[2], profit = tmp[3];
			for(auto next: adj[node]) {
				if(next == parent) continue;
				int next_profit = amount[next];
				int next_time = time + 1;
				if(bob_w.count(next)) {
					if(next_time > bob_w[next]) {
						next_profit = 0;
					} else if(next_time == bob_w[next]) {
						next_profit /= 2;
					}
				}
				q_node_time_parent_profit.push({next, next_time, node, profit + next_profit});
				if(adj[next].size() == 1) {
					res = std::max(res, profit + next_profit);
				}
			}
		}
		return res;
	}
};