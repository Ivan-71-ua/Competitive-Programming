#include <bits/stdc++.h>


const long long INF = 1e18;



int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<long long> weight_vertex(N + 1);
	for (int i = 1; i <= N; i++)
	{
		std::cin >> weight_vertex[i];
	}
	std::vector<std::vector<std::pair<int, long long>>> edges_to_weight(N + 1);
	for (int i = 0; i < M; i++)
	{
		long long m;
		int a, b;
		std::cin >> m >> a >> b;
		edges_to_weight[a].push_back({b, m});
		edges_to_weight[b].push_back({a, m});
	}
	std::vector<long long> dist(N + 1, INF);
	dist[1] = weight_vertex[1];
	std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>> q;
	q.push({weight_vertex[1], 1});
	while(!q.empty()) {
		auto pr = q.top();
		q.pop();
		if(pr.first != dist[pr.second]) continue;
		for (auto &now: edges_to_weight[pr.second])
		{
			long long new_dist = dist[pr.second] + now.second + weight_vertex[now.first];
			if(new_dist < dist[now.first]) {
				dist[now.first] = new_dist;
				q.push({new_dist, now.first});
			}
		}
	}
	for (int i = 2; i <= N; i++)
	{
		std::cout << dist[i] << ' ';
	}
	return 0;
}
