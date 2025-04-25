#include <bits/stdc++.h>

int n, h, l;
std::queue<int> way;

void BFS(std::vector<std::vector<int>> &ver, std::vector<int> &dist) {
	while(!way.empty()) {
		int tmp = way.front();
		way.pop();
		for (auto now: ver[tmp])
		{
			if(dist[now] == INT32_MAX) {
				dist[now] = 1 + dist[tmp];
				way.push(now);
			}
		}
	}
}

int main() {
	std::cin >> n >> h >> l;
	std::vector<int> dist(n, INT32_MAX);
	std::vector<std::vector<int>> ver(n);
	for (int i = 0; i < h; i++)
	{
		int k;
		std::cin >> k;
		way.push(k);
		dist[k] = 0;
	}
	for (int i = 0; i < l; i++)
	{
		int a, b;
		std::cin >> a >> b;
		ver[a].push_back(b);
		ver[b].push_back(a);
	}
	BFS(ver, dist);
	int res = -1;
	int id = -1;
	for (int i = 0; i < n; i++)
	{
		if(dist[i] > res) {
			res = dist[i];
			id = i;
		}
	}
	std::cout << id;
}