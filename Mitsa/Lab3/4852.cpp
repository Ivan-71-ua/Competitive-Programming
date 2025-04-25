#include <bits/stdc++.h>

void find_all_way(int s, std::vector<std::vector<int>> &list_edges, std::vector<int> &dist) {
	dist[s] = 0;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> weight_ver;
	weight_ver.push({0, s});
	while(!weight_ver.empty()) {
		auto [cur_w, cur_v] = weight_ver.top();
		weight_ver.pop();
		if(dist[cur_v] < cur_w) continue;
		for (auto next: list_edges[cur_v])
		{
			if(dist[next] > dist[cur_v] + 1) {
				dist[next] = dist[cur_v] + 1;
				weight_ver.push({dist[cur_v] + 1, next});
			}
		} 
	}
}

int main() {
	int n, s;
	std::cin >> n >> s;
	s--;
	std::vector<std::vector<int>> list_edges(n);
	std::vector<int> dist(n, INT32_MAX);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp;
			std::cin >> tmp;
			if(tmp) {
				list_edges[i].push_back(j);
			}
		}
	}
	find_all_way(s, list_edges, dist);
	for (auto now: dist)
	{
		if(now == INT32_MAX) {
			std::cout << -1 << ' ';
		} else {
			std::cout << now << ' ';
		}
	}
}