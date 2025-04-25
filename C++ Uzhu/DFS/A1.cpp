#include <bits/stdc++.h>
int n, m;
void DFS(int k, std::vector<bool> &used, std::vector<std::vector<int>> &v) {
	used[k] = true;
   std::cout << k << ' ';
	for (auto now : v[k])
	{

		if(!used[now]) {
			DFS(now, used, v);
		}
	}
}

int main() {
	std::cin >> n >> m;
   std::vector<bool> used(n + 1, false);
   std::vector<std::vector<int>> v(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		std::cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int k;
	std::cin >> k;
	DFS(k, used, v);
}