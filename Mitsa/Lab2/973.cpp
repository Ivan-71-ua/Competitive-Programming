#include <bits/stdc++.h>

void dfs(int v, std::vector<std::vector<int>> &list_edges, std::vector<long long> &used, std::vector<long long> &cost,
	std::vector<long long> &take, std::vector<long long> &skip) {
	used[v] = 1;
	take[v] = cost[v];
	skip[v] = 0;
	for (auto next: list_edges[v])
	{
		if(!used[next]) {
			dfs(next, list_edges, used, cost, take, skip);
			take[v] += skip[next];
			skip[v] += std::max(take[next], skip[next]);
		}
	}
}

int main() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> list_edges(n + 1);
	std::vector<long long> used(n + 1);
	std::vector<long long> cost(n + 1);
	std::vector<long long> take(n + 1), skip(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		std::cin >> a >> b;
		list_edges[a].push_back(b);
		list_edges[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		std::cin >> cost[i];
	}
	dfs(1, list_edges, used, cost, take, skip);
	std::cout << std::max(take[1], skip[1]);
}