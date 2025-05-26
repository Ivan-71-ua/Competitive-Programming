
#include <bits/stdc++.h>

class Solution {
public:
	int largestPathValue(std::string colors, std::vector<std::vector<int>>& edges) {
		int n = colors.size(), ans = 0, seen = 0;
		std::vector<int> indegree(n, 0);
		std::vector<std::vector<int>> graph(n, std::vector<int>(26, 0));
		std::vector<std::vector<int>> adj(n);
		for (int i = 0; i < edges.size(); i++) {
			int u = edges[i][0], v = edges[i][1];
			adj[u].push_back(v);
			indegree[v]++;
		}
		std::queue<int> q;
		for (int i = 0; i < n; i++) {
			if(indegree[i] ==0) {
				q.push(i);
			}
		}
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			seen++;
			int8_t color = colors[u] - 'a';
			graph[u][color]++;
			ans = std::max(ans, graph[u][color]);
			for (auto v: adj[u]) {
				for (int i = 0; i < 26; i++) {
					graph[v][i] = std::max(graph[v][i], graph[u][i]);
				}
				indegree[v]--;
				if(indegree[v] == 0) {
					q.push(v);
				}
			}
		}
		std::cout << "ans: " << seen << std::endl;
		if(seen == n) {
			return ans;
		}
		return -1;
	}
};