#include <bits/stdc++.h>

int find_dist(int s, int f, int n, std::vector<std::vector<std::pair<int, int>>> &list_edges, std::vector<int> &dist) {
	dist[s] = 0;
	std::deque<int> q;
	q.push_front(s);
	while(!q.empty()) {
		int v = q.front();
		q.pop_front();
		for (auto next: list_edges[v])
		{
			auto [next_v, weight_n] = next;
			if(dist[next_v] > dist[v] + weight_n) {
				dist[next_v] = dist[v] + weight_n;
				if(weight_n == 1) {
					q.push_back(next_v);
				} else {
					q.push_front(next_v);
				}
			}
		}
	}
	if(dist[f] == INT32_MAX) {
		return -1;
	} else {
		return dist[f];
	}
}

int main() {
	int n, a, b;
	std::cin >> n >> a >> b;
	std::vector<std::vector<std::pair<int, int>>> list_edges(n + 1);
	std::vector<int> dist(n + 1, INT32_MAX);
	for (int v = 1; v <= n; v++)
	{
		int k;
		std::cin >> k;
		for (int i = 0; i < k; i++)
		{
			int next, weight;
			std::cin >> next;
			if(i == 0)
				weight = 0;
			else
				weight = 1;
			list_edges[v].push_back({next, weight});
		}
	}
	std::cout << find_dist(a, b, n, list_edges, dist) << '\n';
}