#include <bits/stdc++.h>


class Solution {
public:
	std::vector<int> shortestDistanceAfterQueries(int n, std::vector<std::vector<int>>& queries) {
		std::vector<int> ans(queries.size());
		std::vector<std::vector<std::pair<int, int>>> adges(n);
		for (int i = 0; i < n - 1; i++) {
			adges[i].push_back({i + 1, 1});
		}
		for (int i = 0; i < queries.size(); i++) {
			adges[queries[i][0]].push_back({queries[i][1], 1});
			std::vector<int> dist(n, INT_MAX);
			std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
			q.push({0, 0});
			dist[0] = 0;
			while (!q.empty()) {
				auto [weight, ver] = q.top();
				q.pop();
				if (weight > dist[ver]) continue;
				for (auto [next, next_weight] : adges[ver]) {
					if (weight + next_weight < dist[next]) {
						dist[next] = weight + next_weight;
						q.push({weight + next_weight, next});
					}
				}
			}
			ans[i] = dist[n - 1];
		}
		return ans;
	}
};