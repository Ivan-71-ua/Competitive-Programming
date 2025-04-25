#include <bits/stdc++.h>

int flag = 0;

void dfs(int v, std::vector<std ::vector<int>> &list_edges, std::vector<int> &used) {
	if(used[v] == 2 || flag)
		return;
	if(used[v] == 1) {
		flag = 1;
		return;
	}
	used[v] = 1;
	for (auto next: list_edges[v])
	{
		dfs(next, list_edges, used);
	}
	used[v] = 2;
}


int main() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> list_edges(n);
	std::vector<int> used(n);
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
	for (int i = 0; i < n; i++)
	{
		if(used[i] == 0) dfs(i, list_edges, used);
	}
	
	std::cout << flag;
}