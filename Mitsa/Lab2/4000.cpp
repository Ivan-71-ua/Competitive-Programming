#include <bits/stdc++.h>


void dfs(int v, int &ans, std::vector<std::vector<int>> &list_edges, std::vector<int> &used) {
	used[v] = 1;
	ans++;
	for (auto next: list_edges[v])
	{
		if(!used[next]) {
			dfs(next, ans, list_edges, used);
		}
	}
}
int main() {
	int n, v, ans = 0;
	std::cin >> n >> v;
	std::vector<int> used(n);
	std::vector<std::vector<int>> list_edges(n);
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
	dfs(v - 1, ans, list_edges, used);
	std::cout <<  ans;
}