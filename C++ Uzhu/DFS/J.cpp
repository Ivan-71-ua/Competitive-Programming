#include <bits/stdc++.h>

int DFS(int k, std::vector<std::vector<int>> &v, std::vector<bool> &used, int &weight) {
	used[k] = true;
	int s = 1;
	for (auto now: v[k])
	{
		if(!used[now]) {
				s += DFS(now, v, used, weight);
		}
	}
	if(s % 2 == 0)
		weight++;
	return s;
}


int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> v(n + 1);
	std::vector<bool> used(n + 1);
	int weight;
	for (int i = 0; i < m; i++)
	{
		int a , b;
		std::cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	DFS(1, v, used, weight);
	std::cout << weight - 1;
}