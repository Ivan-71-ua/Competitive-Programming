#include <bits/stdc++.h>

std::vector<int> BFS(const std::vector<std::vector<int>>& graph, int src, std::vector<int>& dist) {
	int n = graph.size();
	std::vector<int> used(n, 0);
	std::queue<int> q;
	q.push(src);
	used[src] = 1;
	dist[src] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int to : graph[v]) {
				if (!used[to]) {
					used[to] = 1;
					dist[to] = dist[v] + 1;
					q.push(to);
				}
		}
	}
	return used;
}

std::vector<int> findTreeCenters(const std::vector<std::vector<int>>& graph) {
	int n = graph.size();
	std::vector<int> dist1(n), dist2(n);
	
	BFS(graph, 1, dist1);
	int farthest = 1;
	for (int i = 1; i < n; i++) {
		if (dist1[i] > dist1[farthest]) {
				farthest = i;
		}
	}
	
	BFS(graph, farthest, dist1);
	int otherFarthest = farthest;
	for (int i = 1; i < n; i++) {
		if (dist1[i] > dist1[otherFarthest]) {
				otherFarthest = i;
		}
	}
	
	BFS(graph, otherFarthest, dist2);
	int diameter = dist1[otherFarthest];
	std::vector<int> centers;
	int radius = (diameter + 1) / 2;
	for (int i = 1; i < n; i++) {
		if (dist1[i] == radius && dist2[i] == diameter - radius) {
				centers.push_back(i);
		} else if (dist2[i] == radius && dist1[i] == diameter - radius) {
				centers.push_back(i);
		}
	}
	return centers;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> graph(n + 1);
	for (int i = 2; i <= n; i++) {
		int parent;
		std::cin >> parent;
		graph[parent].push_back(i);
		graph[i].push_back(parent);
	}
	std::vector<int> centers = findTreeCenters(graph);
	for (int center : centers) {
		std::cout << center << " ";
	}
	std::cout << std::endl;
}
