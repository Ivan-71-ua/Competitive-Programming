#include <bits/stdc++.h>



class Graph {
	std::vector<std::vector<std::pair<int, int>>> list;
public:
	Graph(int n, std::vector<std::vector<int>>& edges) {
		list.resize(n);
		for (auto now: edges)
		{
			list[now[0]].push_back({now[1], now[2]});
		}
	}
	void addEdge(std::vector<int> edge) {
		list[edge[0]].push_back({edge[1], edge[2]});
	}
	
	int shortestPath(int node1, int node2) {
		std::vector<int> dist(list.size(), INT32_MAX);
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
		q.push({node1, 0});
		dist[node1] = 0;
		while(!q.empty()) {
			auto [ver, weight] = q.top();
			q.pop();
			if(weight > dist[ver]) continue;
			for (auto [to, to_weight]: list[ver])
			{
				if(weight + to_weight < dist[to]) {
					dist[to] = weight + to_weight;
					q.push({to, weight + to_weight});
				}
			}
		}
		if(dist[node2] == INT32_MAX) {
				return -1;
			}
		return dist[node2];
	}
};