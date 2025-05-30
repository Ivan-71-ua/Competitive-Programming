
#include <bits/stdc++.h>


class Solution {
public:
	int closestMeetingNode(std::vector<int>& edges, int node1, int node2) {
		int n = edges.size();
		std::vector<std::vector<int>> adj(n);
		std::vector<int> dist1(n, INT_MAX);
		for (int i = 0; i < n; i++) {
			if (edges[i] != -1) {
				adj[i].push_back(edges[i]);
			}
		}
		std::queue<int> q;
		q.push(node1);
		dist1[node1] = 0;
		while(!q.empty()) {
			int node = q.front();
			q.pop();
			for (auto next: adj[node]) {
				if (dist1[next] > dist1[node] + 1) {
					dist1[next] = dist1[node] + 1;
					q.push(next);
				}
			}
		}
		std::vector<int> dist2(n, INT_MAX);
		q.push(node2);
		dist2[node2] = 0;
		while(!q.empty()) {
			int node = q.front();
			q.pop();
			for (auto next: adj[node]) {
				if (dist2[next] > dist2[node] + 1) {
					dist2[next] = dist2[node] + 1;
					q.push(next);
				}
			}
		}
		int ans = -1, dist = INT_MAX;
		for (int i = 0; i < n; i++) {
			if(dist1[i] != INT_MAX && dist2[i] != INT_MAX) {
				int maxDist = std::max(dist1[i], dist2[i]);
				if (maxDist < dist) {
					dist = maxDist;
					ans = i;
				} else if (maxDist == dist && i < ans) {
					ans = i;
				}
			}
		}
		return ans;
	}
};